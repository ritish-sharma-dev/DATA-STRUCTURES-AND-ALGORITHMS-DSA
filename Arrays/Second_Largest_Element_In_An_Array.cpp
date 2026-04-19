#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // BRUTE FORCE APPROACH
    // TC : O(NlogN)
    // SC : O(1)
    int secondLargestElement(vector <int> &arr){
        sort(arr.begin(), arr.end());
        return arr[arr.size()-2];
    }
    
    
    // OPTIMAL APPROACH
    // TC : O(N)
    // SC : O(1)
    int secondLargestElement(vector <int> &arr){
        int largest = INT_MIN;
        int secLargest = INT_MIN;
        int n = arr.size();
        for (int i=0; i<n; i++){
            if (arr[i] > largest ){
                secLargest = largest;
                largest = arr[i];
            }else if (arr[i] < largest && arr[i] > secLargest){
                secLargest = arr[i];
            }
        }
        return secLargest;
    }
};

int main()
{
    Solution s1;
    vector <int> arr = {50,3,21,500,90,20};
    int largest = s1.secondLargestElement(arr);
    cout<<"Second Largest Element In Array: "<<largest<<endl;
    return 0;
}