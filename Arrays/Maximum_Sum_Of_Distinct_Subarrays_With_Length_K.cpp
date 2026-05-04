// LEETCODE - 2461. Maximum Sum of Distinct Subarrays With Length K


// OPTIAMAL APPROACH - SLIDING WINDOW + FREQUENCY ARRAY
// the question said that we want the maxSum of a subarray of length k but that subarray should have distinct elements. So the intution that comes in my mind is that rather than getting all subarrays i only check the subarrays of length k and this is done with the help of sliding window. Now we want distinct elements in the subarray of length k so we can maintain a frequency array and a variable to count the number of distinct elements in the current window. If the number of distinct elements is equal to k then we can update our maxSum. We will keep on sliding the window until we reach the end of the array.
// TC : O(k + n - k) = O(n)
// SC : O(1)
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> freq(100001,0);

        int i = 0, j = k-1;
        long long sum = 0, maxSum = 0;
        int distinctCount = 0;

        for (int l=0; l<k; l++){
            sum += nums[l];
            freq[nums[l]]++;
            if (freq[nums[l]] == 1) distinctCount++;
        }

        while (j < n){
            if (distinctCount == k) maxSum = max(sum, maxSum);
            j++;
            if (j >= n) break;
            sum += nums[j];
            freq[nums[j]]++;
            if (freq[nums[j]] == 1) distinctCount++;
            sum -= nums[i];
            if (freq[nums[i]] == 1) distinctCount--;
            freq[nums[i]]--;
            i++;
        }
        return maxSum;
    }
};