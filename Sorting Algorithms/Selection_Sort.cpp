#include<bits/stdc++.h>
using namespace std;


void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;

}


void selectionSort(vector <int> &arr, int n)
{
    for (int i=0; i<n-1; i++){
        int minIndex = i;
        for (int j=i+1; j<n; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
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
    selectionSort(arr,n);
    cout<<"After Sorting: ";
    printArray(arr,n);
    return 0;
}