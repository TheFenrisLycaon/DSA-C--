from typing import *


class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        result = 0;
        while (startValue < target) :
            result+=1;
            if target % 2 == 0: target = target//2;
            else: target+=1;
        return result+startValue-target;
