#include <bits/stdc++.h>
using namespace std;

// Function to print array elements to a file
void printArr(vector<int> arr, int n, string filename) {
    ofstream outputfile(filename);
    for (int i = 0; i < n; i++) {
        outputfile << arr[i] << " ";
    }
    outputfile.close();
}

// Function to perform Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to perform Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to generate random numbers and store them in a file
void randomNums(int n) {
    vector<int> arr;
    ofstream outputfile("input.txt");
    for (int i = 0; i < n; i++) {
        outputfile << rand() % (n + 1) << " ";
    }
    outputfile.close();
}

// Function to run sorting algorithms and measure their execution time
void runner(int num) {
    randomNums(num); // put number of numbers to generate

    clock_t startTime, endTime;
    double totalTime;

    vector<int> arr;
    ifstream readfile("input.txt");

    int value;
    while (readfile >> value) {
        arr.push_back(value);
    }
    readfile.close();

    // Quick Sort
    startTime = clock();
    quickSort(arr, 0, arr.size() - 1);
    printArr(arr, arr.size(), "quickSort.txt");
    endTime = clock();

    cout << num;
    totalTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    cout << "        " << totalTime;

    // Heap Sort
    startTime = clock();
    heapSort(arr, arr.size());
    printArr(arr, arr.size(), "heapSort.txt");
    endTime = clock();

    totalTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    cout << "             " << fixed << setprecision(6) << totalTime << endl;
}

// Main function
int main() {
    cout << "          Quick Sort       Heap Sort" << endl;

    // Running sorting algorithms for different input sizes
    runner(1000);
    runner(1500);
    runner(2000);
    runner(2500);
    runner(3000);
    runner(3500);
    runner(4000);
    runner(4500);
    runner(5000);

    return 0;
}
