import hashlib

BLOCKSIZE = 65536  # Block read size if file is big enough

fileToOpen = "/home/omkarpathak/Documents/GITs/Python-Programs/Scripts/howto.txt"
hasher = hashlib.md5()

with open(fileToOpen, "rb") as afile:
    buf = afile.read(BLOCKSIZE)
    while len(buf) > 0:
        hasher.update(buf)
        buf = afile.read(BLOCKSIZE)

print((hasher.hexdigest()))
