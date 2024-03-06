def accum(s):
    return "-".join([((i + 1) * j.lower()).capitalize() for i, j in enumerate(list(s))])


print(
    accum("ZpglnRxqenU")
    == "Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu"
)
