import time

print("Press ENTER to begin, Press Ctrl + C to stop")
while True:
    try:
        eval(input())  # For ENTER
        starttime = time.time()
        print("Started")
    except KeyboardInterrupt:
        print("Stopped")
        endtime = time.time()
        print(("Total Time:", round(endtime - starttime, 2), "secs"))
        break
