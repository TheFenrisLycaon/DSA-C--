def merge_sort(L):
    """Sort the array usin merge sorting"""

    # Calculate the value of middle index of array
    mid = int((len(L) - 1) / 2)

    # This loop will run when length of array is greater than 2
    # a is initialised with left side of the array
    # b is initialised with right side of the array
    if len(L) > mid + 2:
        a = merge_sort(L[0:mid])
        b = merge_sort(L[mid : len(L)])

    # This loop will when length of array is equal to 2
    # a is initiliased with the first element of array
    # b is initiliased with the second element of array
    elif len(L) == 2:
        a = [L[0]]
        b = [L[1]]

    else:
        return L

    i = 0
    j = 0
    new = []

    # This loop will run until
    # i is not equal to the lenth of array a OR
    # j is equal to length of array b
    while i != len(a) or j != len(b):

        # Checking if value of i and j is lesser than length of array a and b
        if i < len(a) and j < len(b):
            # If the element on the left side is lesser
            # The element on the right side
            # Left side element is added to the array new
            if a[i] < b[j]:
                new += [a[i]]
                i += 1

            # If element on the right side is lesser
            # The element on the left side
            # Right side element is added to the array new
            else:
                new += [b[j]]
                j += 1

        # If i gets equal to the length of array a
        # All the elements of array b are directly added to the array new
        elif i == len(a) and j != len(b):
            new += [b[j]]
            j += 1

        # If j gets equal to the length of array b
        # All the elements of array a are directly added to the array new
        elif j == len(b) and i != len(a):
            new += [a[i]]
            i += 1

        else:
            break

    return new


if __name__ == "__main__":
    array = list(map(int, input("Enter array::\t").split()))
    print(merge_sort(array))
