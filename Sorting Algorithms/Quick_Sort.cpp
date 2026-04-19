#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;

}

int findPivotIndex(vector <int> &arr, int start, int end){
    int pivotIndex = start;
    int i = start;
    int j = end;
    while (i <= j){
        while (i<= end && arr[i] <= arr[pivotIndex]){
            i++;
        }
        while (j>=start && arr[j] > arr[pivotIndex]){
            j--;
        }
        if (i < j) swap(arr[i++], arr[j--]);
    }
    swap(arr[pivotIndex], arr[j]);
    return j;
}

void quickSort(vector <int> &arr, int start, int end){
   if (start >= end) return;
   int partition = findPivotIndex(arr, start, end);
   quickSort(arr, start, partition-1);
   quickSort(arr, partition+1, end);
}


void printArray(vector <int> &arr, int n)
{
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void insertInArray(vector <int> &arr,int n)
{
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
}


int main()
{
    int n;
    cout<<"Enter Size: ";
    cin>>n;
    vector <int> arr(n,0);
    cout<<"Enter Values: ";
    insertInArray(arr,n);
    quickSort(arr, 0, n-1);
    cout<<"After Sorting: ";
    printArray(arr,n);
    return 0;
}