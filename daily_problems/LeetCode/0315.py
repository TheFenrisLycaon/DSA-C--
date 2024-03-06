from typing import *


class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        s = list(s)
        stack = []
        for idx, c in enumerate(s):
            if c == "(":
                stack.append(idx)
            elif c == ")":
                if stack:
                    stack.pop()
                else:
                    s[idx] = ""
        while stack:
            s[stack.pop()] = ""
        return "".join(s)
