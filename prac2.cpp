#include<bits/stdc++.h>
using namespace std;

// Function to print array elements to a file
void printArr(vector <int> arr, int n, string filename){
    ofstream outputfile(filename);
    for(int i=0; i<n; i++){
        outputfile << arr[i]<< " ";
    }
    outputfile.close();
}

// Function to perform Insertion Sort and print sorted array to a file
void insertionSort(vector <int> arr, int n){
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printArr(arr, n, "insertionSort.txt");
}

// Function to perform Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// Function to generate random numbers and store them in a file
void randomNums(int n){
    vector <int> arr;
    ofstream outputfile("input.txt");
    for(int i=0; i<n; i++){
        outputfile << rand() % (n+1)<< " ";
    }
    outputfile.close();
}

// Function to run sorting algorithms and measure their execution time
void runner(int num){
    randomNums(num); // put number of numbers to generate

    clock_t startTime, endTime;
    double totalTime;

    vector <int> arr;
    ifstream readfile("input.txt");

    int value;
    while(readfile >> value){
        arr.push_back(value);
    }
    readfile.close();

    // Insertion Sort
    startTime = clock();
    insertionSort(arr, arr.size());
    endTime = clock();

    cout<<num;
    totalTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    cout<<"        "<<totalTime;
    
    // Merge Sort
    startTime = clock();
    mergeSort(arr, 0, arr.size() - 1);
    printArr(arr, arr.size(), "mergeSort.txt");
    endTime = clock();

    totalTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    cout<<"             "<<fixed << setprecision(6) << totalTime<<endl;
}

// Main function
int main(){
    cout<<"          Insertion Sort       Merge Sort"<<endl;

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