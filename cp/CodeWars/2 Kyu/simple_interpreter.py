import re
from numbers import Number
import operator as op


def tokenize(expression):
    if expression == "":
        return []

    regex = re.compile(
        "\s*(=>|[-+*\/\%=\(\)]|[A-Za-z_][A-Za-z0-9_]*|[0-9]*\.?[0-9]+)\s*"
    )
    tokens = regex.findall(expression)
    return [s for s in tokens if not s.isspace()]


def is_number(d):
    p = re.compile(r"\A[-]?\d+(?:\.\d+)?\Z")
    m = p.search(d)
    return bool(m)


def is_operator(o):
    p = re.compile(r"\A[\+\-\*\/\%]\Z")
    m = p.search(o)
    return bool(m)


class Interpreter:
    def __init__(self):
        self.vars = {}
        self.functions = {}
        self.operators = {
            "+": op.add,
            "-": op.sub,
            "*": op.mul,
            "/": op.truediv,
            "%": op.mod,
        }

    def input(self, expression):
        tokens = tokenize(expression)
        # print("tokens: %r" % tokens)

        if "=" in tokens:
            assert tokens[1] == "="
            new_var = tokens[0]
            tokens = tokens[2:]
            value = self.eval_postfix(self.shunting_yard(tokens))
            self.vars[new_var] = value
        else:
            value = self.eval_postfix(self.shunting_yard(tokens))
        return value

    def precedence(self, operator):
        if operator == "+" or operator == "-":
            return 2
        elif operator == "*" or operator == "/" or operator == "%":
            return 3
        else:
            raise Exception("%s is not a valid operator." % operator)

    def shunting_yard(self, expression):
        output = []
        operators = []
        last = ""
        for token in expression:
            if is_number(token):
                if last == "number":
                    raise Exception("ERROR: Invalid syntax: %r" % expression)
                    return
                last = "number"
                try:
                    output.append(int(token))
                except ValueError:
                    output.append(float(token))
            elif token in self.vars:
                if last == "number":
                    raise Exception("ERROR: Invalid syntax: %r" % expression)
                    return
                last = "number"
                output.append(self.vars[token])
            elif token in self.operators:
                last = "operator"
                if operators and is_operator(operators[-1]):
                    o1 = self.precedence(token)
                    o2 = self.precedence(operators[-1])
                    while operators and operators[-1] in self.operators and o2 >= o1:
                        o2 = self.precedence(operators[-1])
                        output.append(self.operators[operators.pop()])
                operators.append(token)
            elif token == "(":
                last = "left_paren"
                operators.append(token)
            elif token == ")":
                last = "right_paren"
                while operators and operators[-1] != "(":
                    output.append(self.operators[operators.pop()])
                try:
                    par = operators.pop()
                except IndexError:
                    raise Exception("ERROR: Mismatched parentheses!")
                    return
            else:
                raise Exception("ERROR: Invalid token: %r" % token)
                return
        while operators:
            output.append(self.operators[operators.pop()])
        return output

    def eval_postfix(self, expression):
        if expression is None:
            return ""
        output = []
        for token in expression:
            if isinstance(token, Number):
                output.insert(0, token)
            else:
                right = output.pop(0)
                left = output.pop(0)
                result = token(left, right)
                output.insert(0, result)
        try:
            return output[0]
        except IndexError:
            return ""
