import matplotlib.pyplot as plt
import numpy as np

# Data for Quick Sort
num_a = np.array([ 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000])
tc_a = np.array([ 0.000007, 0.000006, 0.000007, 0.000005, 0.000005, 0.000006, 0.000006, 0.000006])

# Data for Heap Sort
num_b = np.array([ 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000])
tc_b = np.array([ 0.000005, 0.000005, 0.000005, 0.000005, 0.000005, 0.000005, 0.000005, 0.000005])

plt.plot(num_a, tc_a, label='Quick Sort')
plt.plot(num_b, tc_b, label='Heap Sort')
plt.xlabel('Size of array')
plt.ylabel('Time Complexity')
plt.title('Time Complexity Comparison: Quick Sort vs Heap Sort')
plt.legend()
plt.show()
