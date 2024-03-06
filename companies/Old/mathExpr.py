class Calculator(object):
    def evaluate(self, string):
        expr = string.split()

        for i in range(len(expr) - 1):
            if expr[i] == "(":
                start = i
                temp = []
                while expr[i] != ")":
                    temp.append(expr[i])
                    i += 1
                    end = i
                expr[start:end] = [temp]

        for i in range(len(expr) - 1):
            if expr[i] == "/":
                temp = float(expr[i - 1]) / float(expr[i + 1])
                expr[i] = temp
                expr[i - 1 : i + 1] = [temp]

        # for i in range(len(expr)-1):
        #     if expr[i] == '*':
        #         temp = float(expr[i-1]) * float(expr[i+1])
        #         expr[i] = temp
        #         expr = expr[:i-1] + [temp] + expr[i+1:]

        # for i in range(len(expr)-1):
        #     if expr[i] == '+':
        #         temp = float(expr[i-1]) + float(expr[i+1])
        #         expr[i] = temp
        #         expr = expr[:i-1] + [temp] + expr[i+1:]

        # for i in range(len(expr)-1):
        #     if expr[i] == '-':
        #         temp = float(expr[i-1]) - float(expr[i+1])
        #         expr[i] = temp
        #         expr = expr[:i-1] + [temp] + expr[i+1:]

        return expr


print(Calculator().evaluate("2 / 2 + 3 * 4 - 6"))
