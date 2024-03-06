def count_bits(n):
    binary = str(bin(n).replace("0b", ""))
    return len([x for x in binary if x == '1'])