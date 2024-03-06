class Solution:

    def longestCommonPrefix(self, strs):
        if not strs:
            return ""

        minlen = min((len(string) for string in strs))
        prefix_length = -1
        for i in range(minlen):
            current_char = strs[0][i]
            if not all(string[i] == current_char for string in strs):
                break
            else:
                prefix_length = i
        return "" if prefix_length == -1 else strs[0][: prefix_length + 1]
