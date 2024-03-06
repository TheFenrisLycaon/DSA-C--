class TwoSum(object):
    def __init__(self):
        self.internal = []
        self.dic = {}

    def add(self, number):
        self.internal.append(number)
        if number in self.dic:
            self.dic[number] = True
            return
        self.dic[number] = False

    def find(self, value):
        for v in self.internal:
            if value - v in self.dic:
                if v << 1 == value and not self.dic[v]:
                    continue
                return True
        return False
