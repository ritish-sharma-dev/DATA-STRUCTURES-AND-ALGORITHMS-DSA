#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // BRUTE FORCE APPROACH
    // TC : O(NlogN)
    // SC : O(1)
    int largestElement(vector <int> &arr){
        sort(arr.begin(), arr.end());
        return arr[arr.size()-1];
    }
    

    // OPTIMAL APPROACH
    // TC : O(N)
    // SC : O(1)
    int largestElement(vector <int> &arr){
        int largest = INT_MIN;
        int n = arr.size();
        for (int i=0; i<n; i++){
            int value = arr[i];
            if (value > largest){
                largest = value;
            }
        }
        return largest;
    }
};

int main()
{
    Solution s1;
    vector <int> arr = {50,3,21,500,90,20};
    int largest = s1.largestElement(arr);
    cout<<"Largest Element In Array: "<<largest<<endl;
    return 0;
}