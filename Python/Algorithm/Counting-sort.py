def counting_sort(tlist, k, n):
    """ Counting sort algo with sort in place.
        Args:
            tlist: target list to sort
            k: max value assume known before hand
            n: the length of the given list
            map info to index of the count list.
    """

    # Create a count list and using the index to map to the integer in tlist.
    count_list = [0]*(k+1)

    # iterate the tgt_list to put into count list
    for i in range(0, n):
        count_list[tlist[i]] += 1

    # Modify count list
    # Each index of count list is the combined sum of the previous counts
    # Indicate the actual position (or sequence) in the output sequence.
    for i in range(1, k+1):
        count_list[i] = count_list[i] + count_list[i-1]

    flist = [0]*(n)
    for i in range(n-1, -1, -1):
        count_list[tlist[i]] = count_list[tlist[i]]-1
        flist[count_list[tlist[i]]] = (tlist[i])

    return flist


if __name__ == "__main__":
    tlist = list(map(int, input("Enter the list::\t").split()))
    k = max(tlist)
    n = len(tlist)
    flist = counting_sort(tlist, k, n)
    print(flist)
