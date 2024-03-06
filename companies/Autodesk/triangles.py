def is_triangle(a: int, b: int, c: int) -> int:
    return 1 if ((a + b) > c) and ((b + c) > a) and ((a + c) > b) else 0


def check_array(num):
    return [is_triangle(num[i], num[i + 1], num[i + 2]) for i in range(0, len(num) - 2)]


print(check_array([1, 2, 2, 4]))
