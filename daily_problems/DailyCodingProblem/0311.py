"""
cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair.
For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Implement car and cdr.
"""
from typing import *


def cons(a, b):
    def pair(f):
        return f(a, b)

    return pair

def car(pair):
    return pair(lambda a, b: a)

def cdr(pair):
    return pair(lambda a, b: b)


for i in range(int(input())):
    print(car(cons(3,4)))
    print(cdr(cons(3,4)))
