class Solution(object):
    def getRow(self, rowIndex):
        last = [1]
        res = [1]
        for r in range(1, rowIndex + 1):
            res = [1]
            for index in range(len(last) - 1):
                res.append(last[index] + last[index + 1])
            res.append(1)
            last = res
        return res