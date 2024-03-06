class MinStack(object):
    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, x):
        self.stack.append(x)
        if len(self.min_stack) == 0:
            self.min_stack.append(x)
            return
        if x <= self.min_stack[-1]:
            self.min_stack.append(x)
        else:
            self.min_stack.append(self.min_stack[-1])

    def pop(self):
        if len(self.stack) > 0:
            self.min_stack.pop()
            self.stack.pop()

    def top(self):
        if len(self.stack) > 0:
            return self.stack[-1]
        return None

    def getMin(self):
        if len(self.min_stack) > 0:
            return self.min_stack[-1]
        return None
