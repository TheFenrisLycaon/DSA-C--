class Solution:
    def validPalindrome(self, s: str) -> bool:
        i = 0
        while i <= len(s)//2 and s[i] == s[~i]: i += 1
        s = s[i:len(s)-i]
        return s[1:] == s[1:][::-1] or s[:-1] == s[:-1][::-1]
