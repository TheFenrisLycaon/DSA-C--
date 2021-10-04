def quick_sort(array):
    if len(array) <= 1:
        return array
    else:
        return quick_sort([e for e in array[1:]
                           if e <= array[0]]) + [array[0]] +\
            quick_sort([e for e in array[1:] if e > array[0]])
