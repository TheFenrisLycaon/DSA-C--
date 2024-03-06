def format_duration(s):
    y, s = s // 31536000, s % 31536000
    d, s = s // 86400, s % 86400
    h, s = s // 3600, s % 3600
    m, s = s // 60, s % 60

    res = [
        (str(y) + " year" + "s" * (y != 1)) * (y != 0),
        (str(d) + " day" + "s" * (d != 1)) * (d != 0),
        (str(h) + " hour" + "s" * (h != 1)) * (h != 0),
        (str(m) + " minute" + "s" * (m != 1)) * (m != 0),
        (str(s) + " second" + "s" * (s != 1)) * (s != 0),
    ]

    res = ", ".join([x for x in res if x != ""])

    res = " and".join(res.rsplit(",", 1))

    return "now" if res == "" else res


print(format_duration(1))
print(format_duration(62))
print(format_duration(120))
print(format_duration(3600))
print(format_duration(3662))
