from functools import reduce
class UserMainCode(object):
    def largestBinary(cls, input1, input2, input3):
        """
        READ ONLY WALA PART
        """
        def util(x):
            return sum(val * (2**idx) for idx, val in enumerate(x))
        x = sorted(list(reduce(lambda x, y: x + y, input3)))
        return util(x) % 1000000007

se = UserMainCode()
print(se.largestBinary(3, 3, [[0, 0], [0, 0], [1, 0]]))
print(se.largestBinary(3, 3, [[0, 1], [1, 0], [1, 1]]))
