import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

df1 = pd.read_csv('load31.csv')
df2 = pd.read_csv('load32.csv')
df3 = pd.read_csv('load33.csv')

#plt.subplot(2,1,1)

plt.plot(df1['Users'].tolist(),df1['Throughput'].tolist(),color='r',label='Threadpool size = 10')
plt.plot(df2['Users'].tolist(),df2['Throughput'].tolist(),color='b',label='Threadpool size = 20')
plt.plot(df3['Users'].tolist(),df3['Throughput'].tolist(),color='g',label='Threadpool size = 30')

plt.xlabel("Concurrent users")
plt.ylabel("Throughput")
plt.legend()
plt.title("/arithmetic/fibonacci?num=5")

plt.savefig('plot33.png')
