import sys

if len(sys.argv) > 1:

    if sys.argv[1] == "-f":
        print(sys.argv[-1].split(".")[-1], "file")
    else:
        print(
            "\n\tUse -f [Filename] to get the extension of the file.\
                \n\tUse -h to print this message"
        )

else:

    print(input("Enter file name::\t").split(".")[-1], "file")
