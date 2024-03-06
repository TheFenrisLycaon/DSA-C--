def factorial(number):
    """This function finds the factorial of the number passed as argument"""
    if number < 0:
        print("Invalid entry! Cannot find factorial of a negative number")
    if number == 0 or number == 1:
        return 1
    else:
        return number * factorial(number - 1)


if __name__ == "__main__":
    userInput = int(eval(input("Enter the Number to find the factorial of: ")))
    print((factorial(userInput)))
