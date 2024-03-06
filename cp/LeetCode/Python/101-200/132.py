class Solution(object):
    def minCut(self, s):
        ls = len(s)
        cut = [i -1 for i in range(ls + 1)]
        for i in range(ls):
            pos = 0
            while i - pos >= 0 and i + pos < ls and s[i - pos] == s[i + pos]:
                cut[i + pos + 1] = min(cut[i + pos + 1], 1 + cut[i - pos])
                pos += 1
            pos = 1
            while i - pos + 1 >= 0 and i + pos < ls and s[i - pos + 1] == s[i + pos]:
                cut[i + pos + 1] = min(cut[i + pos + 1], 1 + cut[i - pos + 1])
                pos += 1
        return cut[ls]
