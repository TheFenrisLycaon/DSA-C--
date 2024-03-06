with open("WORDS.TXT", "r+") as f:
    txt = f.readlines()
    f.seek(0)
    for line in txt:
        f.write(line.replace("J", "I"))
