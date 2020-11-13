import matplotlib.pyplot as plt
import numpy as np

x = np.arange(0, 7)
y = -51.1 + 49.5 * x

plt.plot(1,   9, marker=".", color="red")
plt.plot(2,  34, marker=".", color="red")
plt.plot(3,  85, marker=".", color="red")
plt.plot(4, 171, marker=".", color="red")
plt.plot(5, 188, marker=".", color="red")
plt.plot(y)

plt.xlim(0, 5.5)
plt.ylim(0, 200)

plt.show()