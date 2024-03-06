from typing import *


def countVowels(S: str) -> int:
    return sum(list(map(S.lower().count, "aeiou")))


print(countVowels(input()))
