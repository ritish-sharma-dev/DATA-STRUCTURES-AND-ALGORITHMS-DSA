// LEETCODE - 1752 Check If Array Is Sorted and Rotated

// BRUTE FORCE APPROACH
// TC : O(N*(N+N)) = O(2N^2)) = O(N^2)
// SC : O(1)
class Solution{
    public:
    bool checkSorted(vector <int> &arr){
        for (int i=0; i<arr.size()-1; i++){
            if (!(arr[i] <= arr[i+1])){
                return false;
            }
        }
        return true;
    }
    bool check(vector<int>& arr) {
        int n = arr.size();
        for (int i=0; i<n; i++){
            int temp = arr[n-1];
            int j;
            for (j=n-1; j>0; j--){
                arr[j] = arr[j-1];
            }
            arr[j] = temp;
            if (checkSorted(arr)) return true; 
        }
        return false;
    }


    // OPTIMAL APPROACH
    // TC : O(N)
    // SC : O(1)
    bool check(vector<int>& arr) {
        int n = arr.size();
        int valueGreaterThanNext = 0;
        int i;
        for (i=0; i<n-1; i++){
            if (arr[i] > arr[i+1]){
                valueGreaterThanNext++;
            }
        }
        if (arr[i] > arr[0]) valueGreaterThanNext++;
        if (valueGreaterThanNext > 1) return false;
        return true;
    }
}