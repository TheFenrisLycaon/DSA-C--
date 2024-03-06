def eval_postfix(text):
    """Return the result of evaluating a postfix expression."""
    stack = []
    tokens = list(text)
    for token in tokens:
        if token.strip() == "":
            continue
        elif token == "+":
            stack.append(stack.pop() + stack.pop())
        elif token == "-":
            next_ele = stack.pop()
            stack.append(stack.pop() - next_ele)
        elif token == "*":
            stack.append(stack.pop() * stack.pop())
        elif token == "/":
            next_ele = stack.pop()
            if next_ele != 0:
                stack.append(stack.pop() / next_ele)
        elif token in "0123456789":
            stack.append(int(token))
        else:
            continue

    return stack.pop()


print(eval_postfix("23+"))
