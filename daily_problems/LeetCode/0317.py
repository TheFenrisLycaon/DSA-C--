from typing import *


class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        temp, res = 0, 0
        for i in range(1, len(s)):
            if s[i] == "(":
                temp += 1
            elif s[i - 1] == "(":
                res += 1 << temp
                temp -= 1
            else:
                temp -= 1
        return res
