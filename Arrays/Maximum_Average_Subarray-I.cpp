// LEETCODE - 643. Maximum Average Subarray I


// BETTER APPROACH - PREFIX SUM
// The question is that find the maximum average of a subarray of length k. So, what i will do i will find out the prefix sum of the array and then i will use the sliding window approach of length k and then find the sum of that window using the prefix sum and then find the average of that window and check if the average of that window is greater than the maximum average then update the maximum average to the average of that window. and slide the window.  Do this for all windows of length k and finally, return the maximum average.
// TC : O(n)
// SC : O(n)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        vector <int> prefixSum;
        int sum = 0;
        for (int x : nums){
            sum += x;
            prefixSum.push_back(sum);
        }

        double maxAverage = INT_MIN;
        int i = 0;
        int j = k-1;
        while (j < n){
            double windowSum = 0;
            windowSum += prefixSum[j];
            windowSum -= (i != 0) ? prefixSum[i-1] : 0;
            double average = windowSum/k;
            cout<<average;
            if (average > maxAverage) maxAverage = average;
            i++;
            j++;
        }
        return maxAverage;
    }
};



// OPTIMAL APPROACH - SLIDING WINDOW
// The question is that find the maximum average of a subarray of length k. So, what i will do i will use the sliding window approach of length k and then find the sum of that window and then find the average of that window and check if the average of that window is greater than the maximum average then update the maximum average to the average of that window. and slide the window. and add new element to the window and remove old element. Do this for all windows of length k and finally, return the maximum average.
// k is length of subarray and n is nums vector length
// TC : O(k + n - k) = O(n)
// SC : O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        double maxAverage = INT_MIN;
        int i = 0;
        int j = k-1;
        double windowSum = 0;
        for (int l=i; l<=j; l++){
            windowSum += nums[l];
        }

        while (j < n){
            double average = windowSum/k;
            if (average > maxAverage) maxAverage = average;
            j++;
            if (j < n) windowSum += nums[j];
            if (i < n) windowSum -= nums[i];
            i++;
        }

        return maxAverage;
    }
};
