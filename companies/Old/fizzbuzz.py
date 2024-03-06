for i in range(1, 101):
    print(
        str(i) * (i % 3 != 0 and i % 5 != 0)
        + "Fizz" * (i % 3 == 0)
        + "Buzz" * (i % 5 == 0)
    )
