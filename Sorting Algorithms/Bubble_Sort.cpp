#include<bits/stdc++.h>
using namespace std;


void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}


void bubbleSort(vector <int> &arr, int n)
{
    for (int i=0; i<n-1; i++){
        bool isSwap = false;
        for (int j=0; j<n-1-i; j++){
            if (arr[j] > arr[j+1]){
                isSwap = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if (!isSwap) break;
    }
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
    bubbleSort(arr,n);
    cout<<"After Sorting: ";
    printArray(arr,n);
    return 0;
}