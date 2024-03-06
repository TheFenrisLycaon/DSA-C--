#!/usr/bin/env python3
import os
import time
import sys
import dask
from dask import delayed
from src.data.input import Input
from src.data.output import Output
from src.scoring.score import Score
from src.algorithms import *
FILES = ["a", "b", "c", "d", "e", "f"]
FILES_TEST = ["a"]


def run_algorithm(algo, file, parameter={}):
    start_time = time.time()
    current_dir = os.getcwd()
    filepath = current_dir + "/input/" + file + ".txt"
    input = Input(filepath, file)
    input.parse()
    output = algo.solve(input, parameter)
    output.write()
    score = Score(output)
    end_time = time.time()
    print("{:<15}".format(algo.getName())
          + " executed input: " + "{:<15}".format(file)
          + " in {:.2f}s".format(end_time - start_time)
          + " | Score: " + "{:<10}".format(score.score)
          + " | Params: " + str(parameter))
    return score.score


def run_algorithm_grid_search(algo, file, parameter_grid=[]):
    start_time = time.time()
    current_dir = os.getcwd()
    filepath = current_dir + "/input/" + file + ".txt"
    input = Input(filepath, file)
    input.parse()
    scores = []
    for p in parameter_grid:
        output = delayed(algo.solve)(input, p)
        score = delayed(Score)(output)
        scores.append((score, output, p))
    scores = dask.compute(*scores, num_workers=4)
    end_time = time.time()
    scores = sorted(scores, key=lambda x: x[0].score, reverse=True)
    score = scores[0][0]
    output = scores[0][1]
    parameter = scores[0][2]
    output.write()
    print("{:<15}".format(algo.getName())
          + " executed input: " + "{:<15}".format(file)
          + " in {:.2f}s".format(end_time - start_time)
          + " | Score: " + "{:<10}".format(score.score)
          + " | Params: " + str(parameter))
    return score.score


if __name__ == "__main__":
    print("-------------------------")
    print("      HashCode 2021      ")
    print("-------------------------")
    start_time_program = time.time()
    scores = []
    for f in FILES:
        res = delayed(run_algorithm_grid_search)(
            BasicAlgorithm(), f, parameter_grid=[1, 2])
        scores.append(res)
    total_scores = delayed(sum)(scores)
    total_scores = total_scores.compute()
    print("Total scores: ", total_scores)
    end_time_program = time.time()
    print("Whole execution took: {:.2f}s".format(
        end_time_program - start_time_program))
