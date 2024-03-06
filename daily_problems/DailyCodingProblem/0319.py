"""
Given an integer k and a string s,
find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2,
the longest substring with k distinct characters is "bcb".
"""
from typing import *

#! NOR WORKING YET
def foo(s, k):
    a = 0
    oc = [0] * 26
    max_len = 0
    first = -1

    for b in range(0, len(s)):
        oc[ord(s[b]) - ord("a")] += 1
        while oc[ord(s[b]) - ord("a")] > k:
            oc[ord(s[a]) - ord("a")] -= 1
            a += 1
        if b - a + 1 > max_len:
            max_len = b - a + 1
            first = a + 1

    print(first)
    print(max_len)


for i in range(int(input())):
    print(foo(input(), int(input())))
