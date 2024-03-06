from typing import *


class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack, i = [], 0

        for element in pushed:
            stack.append(element)
            while len(stack) > 0 and stack[len(stack) - 1] == popped[i]:
                stack.pop()
                i += 1

        return len(stack) == 0
