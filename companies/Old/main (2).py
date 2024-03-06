class stack:
    def __init__(self):
        self.values = []

    def empty(self):
        if len(self.values) == 0:
            return True
        return False


p = stack()
print(p.empty())
