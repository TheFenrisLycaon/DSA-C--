#!/usr/bin/env python3

import sys
from typing import List


class Skill:
    def __init__(self, name: str, level: int) -> None:
        self.name: str = name
        self.level: int = level

    def increment_level(self):
        self.level += 1

    def __repr__(self):
        return f"<Skill {self.name} lvl.{self.level}>"

    def __str__(self):
        return f"{self.name} ::\t{self.level}"


class Developper:
    def __init__(self, name: str, nb_skills: int) -> None:
        self.name = name
        self.nb_skills = nb_skills
        self.skills: List[Skill] = []

        # day where the dev is hooked to a project
        self.calendar = []

    def __repr__(self) -> str:
        s = " - ".join(map(lambda x: x.__repr__(), self.skills))
        return f"<Dev name: {self.name} nb_skills: {self.nb_skills}\n SKILLS: {s}>"

    def assign_skill(self, skill: Skill) -> None:
        self.skills.append(skill)

    def __str__(self):
        return (
            f"{self.name} ::\t{self.nb_skills}"
            + "\n\t"
            + "\t".join(map(lambda x: x.__str__(), self.skills))
        )


class Project:
    def __init__(
        self, name: str, days: int, score: int, best: int, nb_skill: int
    ) -> None:
        self.name = name
        self.days = days
        self.score = score
        self.best = best
        self.nb_skill = nb_skill
        self.required_skills: List[Skill] = []
        self.priority: int = days - best * score / nb_skill

    def assign_required_skill(self, skill: Skill) -> None:
        self.required_skills.append(skill)

    def __repr__(self):
        s = " - ".join(map(lambda x: x.__repr__(), self.required_skills))
        return f"<Project {self.name} days {self.days} score {self.score} best {self.best} nb_skills {self.nb_skill} {s}>"

    def __str__(self):
        return (
            f"{self.name} ::\n \tDays ::\t{self.days} \
                \n\tScore ::\t{self.score} \
                \n\tBest ::\t{self.best} \
                \n\tNumber of Skills ::\t{self.nb_skill}"
            + "\n\t\t"
            + "\t".join(map(lambda x: x.__str__(), self.required_skills))
        )


def getInProjectLine(line: str) -> Project:
    spl = line.split(" ")
    return Project(spl[0], int(spl[1]), int(spl[2]), int(spl[3]), int(spl[4]))


def getInSkillLine(line: str) -> Skill:
    spl = line.split(" ")
    return Skill(spl[0], int(spl[1]))


def getInDevelopperLine(line: str) -> Developper:
    spl = line.split(" ")
    return Developper(spl[0], int(spl[1]))


def nnl(s: str) -> str:
    return s[: len(s) - 1]


def getIn():
    with open(sys.argv[1], "r") as f:
        c = f.readlines()
        head = list(map(int, c[0].split(" ")))
        contributors_nb = head[0]
        projects_nb = head[1]
        x = 1
        devs = []
        projects = []
        for _ in range(contributors_nb):
            dev = getInDevelopperLine(nnl(c[x]))
            x += 1
            for _ in range(dev.nb_skills):
                s = getInSkillLine(nnl(c[x]))
                dev.assign_skill(s)
                x += 1
            devs.append(dev)
        for _ in range(projects_nb):
            project = getInProjectLine(nnl(c[x]))
            x += 1
            for _ in range(project.nb_skill):
                s = getInSkillLine(nnl(c[x]))
                project.assign_required_skill(s)
                x += 1
            projects.append(project)
    return devs, projects


if __name__ == "__main__":
    devs, projects = getIn()
    # print("DEVS\n")
    # for d in devs:
    #     print(d)
    # print()
    # print("PROJECTS\n")
    # for p in projects:
    #     print(p)

    projects.sort(key=lambda x: x.priority, reverse=True)

    print("PROJECTS\n")
    for p in projects:
        print(p.name)
