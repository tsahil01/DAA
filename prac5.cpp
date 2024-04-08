// Knapsack Problem
#include <bits/stdc++.h>
using namespace std;

struct Job{
    string objName;
    int w;    // weight
    int v;    // profit
};

bool compareMaxProfit(Job a, Job b) {
    return (a.v > b.v);
}
bool compareMinWeight(Job a, Job b) {
    return (a.w < b.w);
}
bool compareViWi(Job a, Job b) {
    double x = (double)a.v / a.w;
    double y = (double)b.v / b.w;
    return (x > y);
}

void printDetails(int totJobs, Job arr[]){
        for(int i = 0; i<totJobs; i++){
        cout << endl << "Details of Object "<< i+1 <<" :"<< endl;
        cout << "Object Name: "<< arr[i].objName << endl;
        cout <<"Object Weight: " << arr[i].w << endl;
        cout <<"Object Profit: " << arr[i].v <<endl;
    }
}

void maxProfit(int totJobs, Job arr[]){
    sort(arr, arr + totJobs, compareMaxProfit);
}
void minWeight(int totJobs, Job arr[]){
    sort(arr, arr + totJobs, compareMinWeight);
}
void maxViWi(int totJobs, Job arr[]){
    sort(arr, arr + totJobs, compareViWi);
    printDetails(totJobs, arr);
}

void calculateProfit(int totJobs, Job arr[]){
    int remain = 15;
    int profit = 0;
    for(int i = 0; i<totJobs; i++){
        if(remain > 0){
            if(remain < arr[i].w){
                int temp = arr[i].w;
                arr[i].w = ((remain * arr[i].w)/temp) ;
                arr[i].v = ((remain * arr[i].v)/temp) ;
            }
            remain = remain - arr[i].w;
            profit = profit + arr[i].v;
            cout<<"W: "<<arr[i].w<<" V: "<<arr[i].v<<endl;
            cout<<"Remaining: "<<remain<<endl;
        }
    }
    cout<<endl<<"Total Profit: "<<profit;
}


int main(){
    int totJobs = 0;
    cout<<"Enter total number of Objects: ";
    cin>>totJobs;
    Job arr[totJobs];

    for(int i = 0; i<totJobs; i++){
        cout<<"Enter the details of Object (ObjName, weight, profit)"<< i+1 <<" :";
        cin>>arr[i].objName;
        cin>>arr[i].w;
        cin>>arr[i].v;
    }

    // maxProfit(totJobs, arr);
    minWeight(totJobs, arr);
    // maxViWi(totJobs, arr);
    calculateProfit(totJobs, arr);

    cout<<endl;
    return 0;
}

