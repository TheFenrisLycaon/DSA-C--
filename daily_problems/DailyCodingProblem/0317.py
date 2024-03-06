"""
Implement an autocomplete system.
That is, given a query string s and a set of all possible query strings,
return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal],
return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
"""
from typing import *
import re


def autocomplete(s: str, dictionary: List[str]) -> List[str]:
    return [x for x in dictionary if re.compile("^" + s).match(x)]


for i in range(int(input())):
    print(autocomplete(input(), input().split()))
