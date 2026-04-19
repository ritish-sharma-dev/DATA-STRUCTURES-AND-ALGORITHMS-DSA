// LEETCODE - 2574. Left and Right Sum Difference

// BRUTE FORCE APPROACH
// We can calculate the left sum and right sum for each index and then find the absolute difference between them. Return the answer in an array.
// TC : O(3n) = O(n)
// SC : O(3n) = O(n)
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector <int> leftSum(n);
        vector <int> rightSum(n);
        vector <int> ans(n);

        int i = 0;
        int sum = 0;
        while (i < n){
            leftSum[i] = sum;
            sum += nums[i];
            i++;
        }

        int j = n-1;
        sum = 0;
        while (j >= 0){
            rightSum[j] = sum;
            sum += nums[j];
            j--;
        }

        int k = 0;
        while (k < n){
            ans[k] = abs(leftSum[k] - rightSum[k]);
            k++;
        }

        return ans;
    }
};


// OPTIMAL APPROACH
// We can calculate the right sum first and then iterate through the array to calculate the left sum and update the right sum at each index. This way we can find the absolute difference in one pass.
// TC : O(2n) = O(n)
// SC : O(1)
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        int rightSum = 0;
        for (int i=0; i<n; i++){
            rightSum += nums[i];
        }

        int leftSum = 0;
        for (int i=0; i<n; i++){
            rightSum -= nums[i];
            int absDifference = abs(leftSum - rightSum);
            leftSum += nums[i];
            nums[i] = absDifference;
        }
        return nums;
    }
};