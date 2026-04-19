#include<bits/stdc++.h>
using namespace std;

void merge(vector <int> &arr, int start, int mid, int end){
    int i = start;
    int j = mid+1;
    vector <int> temp;

    while (i<=mid && j<=end){
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i<=mid) temp.push_back(arr[i++]);
    while (j<=end) temp.push_back(arr[j++]);

    for (int k=0; k<temp.size(); k++) {
        arr[start+k] = temp[k];
    }
}


void mergeSort(vector <int> &arr, int start, int end){
    if (start >= end) return;
    int mid = start + (end - start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
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
    mergeSort(arr, 0, n-1);
    cout<<"After Sorting: ";
    printArray(arr,n);
    return 0;
}