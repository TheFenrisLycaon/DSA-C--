import pandas as pd
import numpy as np
import pacman as pc

np.savetxt(r"./pk", pd.read_csv("./pkglist.csv", header=None)[0], fmt="%s")


details = pc.get_info("vlc")

print(details)
