#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // BRUTE FORCE APPROACH
    // TC : O(NlogN)
    // SC : O(1)
    int smallestElement(vector <int> &arr){
        sort(arr.begin(), arr.end());
        return arr[0];
    }


    // OPTIMAL APPROACH
    // TC : O(N)
    // SC : O(1)
    int smallestElement(vector <int> &arr){
        int smallest = INT_MAX;
        int n = arr.size();
        for (int i=0; i<n; i++){
            if (arr[i] < smallest ){
                smallest = arr[i];
            }
        }
        return smallest;
    }
};

int main()
{
    Solution s1;
    vector <int> arr = {50,3,21,500,90,20};
    int largest = s1.smallestElement(arr);
    cout<<"Smallest Element In Array: "<<largest<<endl;
    return 0;
}