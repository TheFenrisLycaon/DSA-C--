class Solution(object):
    def isOneEditDistance(self, s, t):
        ls_s, ls_t = len(s) ,len(t)
        if ls_s > ls_t:
            return self.isOneEditDistance(t, s)
        if ls_t - ls_s > 1:
            return False
        i, shift = 0, ls_t - ls_s
        while i < ls_s and s[i] == t[i]:
            i += 1
        if i == ls_s:
            return shift > 0
        if shift == 0:
            i += 1
        while i < ls_s and s[i] == t[i + shift]:
            i += 1
        return i == ls_s