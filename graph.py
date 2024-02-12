import matplotlib.pyplot as plt
import numpy as np

num = np.array([1000, 2000, 5000, 7500, 9000])

bubble_y_pts = np.array([0.005726, 0.021891, 0.389512, 0.446441])
selection_y_pts = np.array([0.003146,  0.010198,0.094497, 0.162594, 0.188753])

plt.plot(num, bubble_y_pts, label = "Bubble Sort")
plt.show()

