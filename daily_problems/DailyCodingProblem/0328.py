"""
Given a dictionary of words and a string made up of those words (no spaces),
return the original sentence in a list.

If there is more than one possible reconstruction,
return any of them.

If there is no possible reconstruction,
then return null.

For example,
given the set of words 'quick', 'brown', 'the', 'fox',
and the string "thequickbrownfox",
you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond',
and the string "bedbathandbeyond",
return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
"""
from typing import *


def search(string: str, words: List[str]) -> List[str]:
    """
    Given a dictionary of words and a string made up of those words (no spaces),
    return the original sentence in a list.
    """
    for word in words:
        if string.startswith(word):
            return [word] + search(string[len(word) :], words)
    return []


for i in range(int(input())):
    print(search(input(), input().split()))
