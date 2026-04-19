#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // BRUTE FORCE APPROACH
    // TC : O(NlogN)
    // SC : O(1)
    int secondSmallestElement(vector <int> &arr){
        sort(arr.begin(), arr.end());
        return arr[1];
    }
    

    // OPTIMAL APPROACH
    // TC : O(N)
    // SC : O(1)
    int secondSmallestElement(vector <int> &arr){
        int smallest = INT_MAX;
        int secSmallest = INT_MAX;
        int n = arr.size();
        for (int i=0; i<n; i++){
            if (arr[i] < smallest ){
                secSmallest = smallest;
                smallest = arr[i];
            }else if (arr[i] > smallest && arr[i] < secSmallest){
                secSmallest = arr[i];
            }
        }
        if (secSmallest == INT_MAX) return -1;
        return secSmallest;
    }
};

int main()
{
    Solution s1;
    vector <int> arr = {50,3,21,500,90,20};
    int largest = s1.secondSmallestElement(arr);
    cout<<"Second Smallest Element In Array: "<<largest<<endl;
    return 0;
}