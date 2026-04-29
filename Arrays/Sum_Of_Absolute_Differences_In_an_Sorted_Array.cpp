// LEETCODE - 1685. Sum of Absolute Differences in a Sorted Array


// BRUTE FORCE APPROACH
// We can use two nested loops to calculate the sum of absolute differences for each element in the array. The outer loop iterates through each element, while the inner loop calculates the absolute difference between the current element and all other elements, summing them up. Finally, we store the result in a new array and return it.
// TC : O(n^2)
// SC : O(1) (do not considering the result array)
// AS : O(1)
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector <int> result(n);

        for (int i=0; i<n; i++){
            int sumOfAbsoluteDifferences = 0;
            for (int j=0; j<n; j++){
                if (i != j) sumOfAbsoluteDifferences += abs(nums[i]-nums[j]);
            }
            result[i] = sumOfAbsoluteDifferences;
        }
        return result;
    }
};


// BETTER APPROACH
// TC : O(2n) = O(n)
// SC : O(2n) = O(n) (considering the prefix sum array and the result array or you may not consider the result array as it is the output space)
// AS : O(n)
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector <int> prefixSumArray;
        int prefixSum = 0;
        for (int i=0; i<n; i++){
            prefixSum += nums[i];
            prefixSumArray.push_back(prefixSum);
        }

        vector <int> result;
        for (int i=0; i<n; i++){
            int leftSum =(i!= 0) ? prefixSumArray[i-1] : 0;
            int leftSide = nums[i]*i - leftSum;

            int rightSum = prefixSumArray[n-1] - prefixSumArray[i];
            int rightSide = rightSum - nums[i]*(n-1-i);

            int sumOfAbsoluteDifference = leftSide + rightSide;
            result.push_back(sumOfAbsoluteDifference);
        }

        return result;
    }
};


// OPTIMIZED APPROACH
// TC : O(2n) = O(n)
// SC : O(1) (i am not considering the output space here)
// AS : O(1)
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector <int> result;

        int rightSum = 0;
        for (int i=0; i<n; i++){
            rightSum += nums[i];
        }

        int leftSum = 0;
        for (int i=0; i<n; i++){
            int leftSide = nums[i]*i - leftSum;
            int rightSide = rightSum - (leftSum + nums[i]) - nums[i]*(n-1-i);
            int sumOfAbsoluteDifference = leftSide + rightSide;
            leftSum += nums[i];
            result.push_back(sumOfAbsoluteDifference);
        }

        return result;
    }
};