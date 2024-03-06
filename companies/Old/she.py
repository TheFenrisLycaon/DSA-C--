def get_dist_scale(enteredVal):
    while True:
        try:
            enteredInt = int(enteredVal)
            assert enteredInt <= int(9), "Value greater than 9"
            assert enteredInt >= int(1), "Value less than 1"
            return enteredInt
        except ValueError:
            print("Invalid Input, try again\n")
            main()
        except AssertionError:
            print("Value outside 1-9.\n")
            main()


def main():
    enteredVal = input(
        "1:\tFor Manhattan\
          \n2:\tFor Euclidean\
          \n>=3:\tFor Minkowski\
        \nEnter distance parameter:\
        "
    )
    return get_dist_scale(enteredVal)


print(main())
