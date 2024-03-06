class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        correct_int = list(map(int, correct.split(':')))
        current_int = list(map(int, current.split(':')))
        correct_min = correct_int[0] * 60 + correct_int[1]
        current_min = current_int[0] * 60 + current_int[1]

        diff = correct_min - current_min
        tot = 0
        for i in [60, 15, 5, 1]:
            tot += diff // i
            diff = diff % i
        return tot


print(Solution().convertTime('02:30', '04:35'))