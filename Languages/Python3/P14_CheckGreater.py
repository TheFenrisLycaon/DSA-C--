def checkGreater(number):
    """This function checks whether the entered number is greater than those in the list"""
    original = [1, 2, 3, 4, 5]
    original.sort()
    if number > original[-1]:
        print("Yes, the entered number is greater than those in the list")
    else:
        print("No, entered number is less than those in the list")


if __name__ == "__main__":
    userInput = int(eval(input("Enter the number to check: ")))
    checkGreater(userInput)
