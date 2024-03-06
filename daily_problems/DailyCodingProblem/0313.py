"""
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
"""

from typing import *


def decodeWays(message: str) -> int:
    dp = [0] * (len(message) + 1)
    dp[0], dp[1] = 1, 1
    if message[0] == "0":
        return 0
    for i in range(2, len(message) + 1):
        if 1 <= int(message[i - 1]) <= 9:
            dp[i] += dp[i - 1]
        if 10 <= int(message[i - 2] + message[i - 1]) <= 26:
            dp[i] += dp[i - 2]
    return dp[-1]


for i in range(1):
    print(decodeWays("111"))
