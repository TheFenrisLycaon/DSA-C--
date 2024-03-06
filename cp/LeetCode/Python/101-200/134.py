class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        ls = len(gas)
        begin, end = 0, ls - 1
        curr = gas[end] - cost[end]
        while begin < end:
            if curr >= 0:
                curr += gas[begin] - cost[begin]
                begin += 1
            else:
                end -= 1
                curr += gas[end] - cost[end]
        if curr >= 0:
            return end
        else:
            return -1
