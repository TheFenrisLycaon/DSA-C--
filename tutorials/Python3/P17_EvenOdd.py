def evenOdd(numbers):
    """This function divides the numbers in two arrays one of even and other of odd"""
    even = []
    odd = []
    for number in numbers:
        if int(number) % 2 == 0:
            even.append(number)
        else:
            odd.append(number)
    return even, odd


if __name__ == "__main__":
    userInput = eval(input("Enter the numbers (space separated) to check: "))
    userInput = list(userInput.split())
    even, odd = evenOdd(userInput)
    print(("Even Nos: ", ",".join(even), "\n", "Odd Nos: ", ",".join(odd)))
