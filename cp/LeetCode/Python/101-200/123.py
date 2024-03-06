class Solution(object):
    def maxProfit(self, prices):
        ls = len(prices)
        if ls == 0:
            return 0
        b1 = b2 = -prices[0]
        s1 = s2 = 0
        for i in range(1, ls):
            s2 = max(s2, b2 + prices[i])
            b2 = max(b2, s1 - prices[i])
            s1 = max(b1 + prices[i], s1)
            b1 = max(b1, -prices[i])
        return max(s1, s2)
