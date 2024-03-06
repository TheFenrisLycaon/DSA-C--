from typing import *

class Solution:
    def simplifyPath(self, path: str) -> str:
        tokens = path.split('/')
        stack = []
        ans = '/'
        for item in tokens:
            if item == '':
                continue
            if item == '.':
                pass
            elif item == '..':
                if len(stack) > 0:
                    _ = stack.pop()
            else:
                stack.append(item)
        for item in stack:
            ans += item
            ans += '/'
        return ans if len(ans) == 1 else ans[:-1]
