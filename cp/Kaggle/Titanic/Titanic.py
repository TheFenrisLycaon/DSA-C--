import numpy as np
from seaborn as sns
import pandas as pd
from matplotlib.pyplot as plt

os.chdir('./Kaggle')

testData = pd.read_csv("test.csv")
trainData = pd.read_csv("train.csv")

