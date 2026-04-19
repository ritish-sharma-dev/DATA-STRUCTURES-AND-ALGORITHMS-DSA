// LEETCODE - 26 Remove Duplicates From Sorted Array

// BRUTE FORCE APPROACH
// TC : O(n^2)
// SC : O(1)
class Solution{
    public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        for (int i = 0; i<n; i++){
            bool exist = false;
            for (int j = i+1; j<n; j++){
                if (arr[i] == arr[j]){
                    exist = true;
                }
            }
            if (!exist){
                arr[start] = arr[i];
                start++;
            }
        }
        return start;
    }


    // BETTER APPROACH
    // TC : O(nlogn + n) = O(nlogn)
    // SC : O(n)
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        map <int, int> m;
        for (int i=0; i<n; i++){
            m[nums[i]]++;
        }

        int i=0;
        for (auto x : m){
            nums[i++] = x.first;
        }
        return i;
    }


    // OPTIMAL APPROACH
    // TC : O(n)
    // SC : O(1)
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int value = nums[0];
        int count = 0;
        int start = 0;

        for (int i=0; i<n; i++){
            if (nums[i] == value){
                count++;
            }else{
                value = nums[i];
                count = 1;
            }
            if (count == 1){
                nums[start++] = nums[i];
            }
        }
        return start;
    }


    // TWO POINTERS OPTIMAL APPROACH
    // TC : O(n)
    // SC : O(1)
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int start = 0;
        while (i<n){
            if (nums[i] != nums[start]){
                nums[start+1] = nums[i];
                start++;
            }
            i++;
        }
        return start+1;
    }
};