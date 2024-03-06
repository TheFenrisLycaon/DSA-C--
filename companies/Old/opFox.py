words = ["a", "quick", "brown", "fox", "jumps", "over", "the ", "lazy ", "dog "]
nums = [2, 3, 4, 2]

start = 0
temp = []
for i in nums:
    temp.append(words[start : start + i])
    start = i

for x in temp:
    print(x)
