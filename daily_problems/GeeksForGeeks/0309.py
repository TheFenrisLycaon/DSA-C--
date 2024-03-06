from typing import *


def Push(x: int, stack1: List[int], stack2: List[int]) -> None:
    """
    Function to push an element in queue by using 2 stacks.
    """
    stack1.append(x)


# Function to pop an element from queue by using 2 stacks.
def Pop(stack1: List[int], stack2: List[int]) -> int:

    """
    stack1: list
    stack2: list
    """
    if not stack2:
        while stack1:
            stack2.append(stack1.pop())
    return stack2.pop()


if __name__ == "__main__":
    test_cases = int(input())
    for cases in range(test_cases):
        qry = int(input())
        qtyp_qry = list(map(int, input().strip().split()))

        i = 0
        stack1 = []
        stack2 = []
        while i < len(qtyp_qry):
            # print(i)
            if qtyp_qry[i] == 1:
                Push(qtyp_qry[i + 1], stack1, stack2)
                # print(i)
                i += 2
            else:
                print(Pop(stack1, stack2), end=" ")
                i += 1
