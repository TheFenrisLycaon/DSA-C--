import random


def guess():
    """This function guesses the randomnly generated number"""
    randomNumber = random.randint(0, 21)
    count = 0

    while True:
        count += 1
        number = int(eval(input("Enter the number between 0 to 20: ")))
        if number < randomNumber:
            print("Too small")
        elif number > randomNumber:
            print("Too large")
        else:
            print(("You have got it in", count, "tries"))
            break


if __name__ == "__main__":
    guess()
