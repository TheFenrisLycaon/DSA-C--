class Solution(object):
    def __init__(self):
        self.solution = {}

    def wordBreak(self, s, wordDict):
        try:
            return self.solution[s]
        except KeyError:
            pass
        result = []
        if s in wordDict:
            result.append(s)
        for i in range(1, len(s)):
            word = s[i:]
            if word in wordDict:
                rem = s[:i]
                prev = self.wordBreak(rem, wordDict)
                result.extend([res + ' ' + word for res in prev])
        self.solution[s] = result
        return result
