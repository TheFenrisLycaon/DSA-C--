def binarySearch(arr, left, right, item):
    """
    It returns location of x in given array arr
    if present, else returns -1
    """
    while left <= right:

        # extracting the middle element from the array
        mid = left + (right - left) / 2

        # Check if x is present at mid
        if arr[mid] == item:
            return mid

        # If x is greater, ignore left half
        # l is initialised to the rightmost element of the middle
        # Thus, The search could be started from there the next time
        elif arr[mid] < item:
            left = mid + 1

        # If x is smaller, ignore right half
        # r is initialised to the leftmost element of the middle
        # Thus, the search goes till there only the next time
        elif item < arr[mid]:
            right = mid - 1

    # If we reach here, then the element was not present
    return -1


# Main Function
if __name__ == "__main__":
    arr = list(map(int, input("Enter the array::\t").split()))
    # Apply the given function to each item
    # Map function returns a list of results
    x = eval(input("Enter the element::\t"))

    # Function call
    result = binarySearch(arr, 0, len(arr) - 1, x)

    # printing the output
    if result != -1:
        print("Element is present at index {}".format(result))
    else:
        print("Element is not present in array")
