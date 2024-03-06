from multiprocessing import Process, Pipe


def parentData(parent):
    """This function sends the data for the child process"""
    parent.send(["Hello"])
    parent.close()


def childData(child):
    """This function sends the data for the parent process"""
    child.send(["Bye"])
    child.close()


if __name__ == "__main__":
    parent, child = Pipe()  # Create Pipe

    # Create a process for handling parent data
    process1 = Process(target=parentData, args=(parent,))

    # Create a process for handling child data
    process2 = Process(target=childData, args=(child,))

    process1.start()  # Start the  parent process
    process2.start()  # Start the child process

    # Display data received from child (BYE)
    print((parent.recv()))
    # Display data received from parent (HELLO)
    print((child.recv()))

    process1.join()  # Wait till the process completes its execution
    process2.join()
