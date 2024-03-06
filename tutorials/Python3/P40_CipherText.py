LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
LETTERS = LETTERS.lower()


def encrypt(message, key):
    """This function lets you to encrypt your message based on a key"""
    encrypted = ""
    for chars in message:
        if chars in LETTERS:
            num = LETTERS.find(chars)
            num += key
            encrypted += LETTERS[num]

    return encrypted


def decrypt(message, key):
    """This function lets you to decrypt your message based on a key"""
    decrypted = ""
    for chars in message:
        if chars in LETTERS:
            num = LETTERS.find(chars)
            num -= key
            decrypted += LETTERS[num]

    return decrypted


def main():
    message = str(eval(input("Enter your message: ")))
    key = int(eval(input("Enter you key [1 - 26]: ")))
    choice = eval(input("Encrypt or Decrypt? [E/D]: "))

    if choice.lower().startswith("e"):
        print((encrypt(message, key)))
    else:
        print((decrypt(message, key)))


if __name__ == "__main__":
    main()

    # OUTPUT:
    # omkarpathak@omkarpathak-Inspiron-3542:~/Documents/GITs/Python-Programs/Programs$ python P40_CipherText.py
    # Enter your message: omkar
    # Enter you key [1 - 26]: 2
    # Encrypt or Decrypt? [E/D]: e
    # qomct
    #
    # omkarpathak@omkarpathak-Inspiron-3542:~/Documents/GITs/Python-Programs/Programs$ python P40_CipherText.py
    # Enter your message: qomct
    # Enter you key [1 - 26]: 2
    # Encrypt or Decrypt? [E/D]: d
    # omkar
