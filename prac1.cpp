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

// Function to perform selection sort and print sorted array to a file
void selectionSort(vector <int> arr, int n){
    for(int i = 0; i<n; i++){
        int mini = i;
        for(int j= i+1; j<n; j++)
            if(arr[j]< arr[mini])
                mini = j;
        swap(arr[i], arr[mini]);
    }
    printArr(arr, n, "selectionSort.txt");
}

// Function to perform bubble sort and print sorted array to a file
void bubbleSort(vector <int> arr, int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j< n-1-i; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
    }
    printArr(arr, n, "bubbleSort.txt");
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

    // Bubble Sort
    startTime = clock();
    bubbleSort(arr, arr.size());
    endTime = clock();

    cout<<num;
    totalTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    cout<<"        "<<totalTime;
    
    // Selection Sort
    startTime = clock();
    selectionSort(arr, arr.size());
    endTime = clock();

    totalTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    cout<<"             "<<fixed << setprecision(6) << totalTime<<endl;
}

// Main function
int main(){
    cout<<"          Bubble Sort         Selection Sort"<<endl;

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
