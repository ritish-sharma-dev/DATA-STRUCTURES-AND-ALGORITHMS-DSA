// LEETCODE - 16    3Sum Closest


// BRUTE FORCE APPROACH
// I will found every possible combination of three numbers and calculate their sum and find the difference between the target and the threesum. if the difference is less than the minimum difference then i will update the minimum difference and the three sum closest to the sum of three values threesum. Finally, i will return the the sum of the three integers. 
// TC : O(n^3)
// SC : O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int minDifference = INT_MAX;
        int threeSumClosest = 0;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                for (int k=j+1; k<n; k++){
                    int threeSum = nums[i] + nums[j] + nums[k];
                    int difference = abs(target - threeSum);
                    if (difference < minDifference){
                        minDifference = difference;
                        threeSumClosest = threeSum;
                    }
                }
            }
        }
        return threeSumClosest;
    }
};


// OPTIMAL APPROACH
// I will sort the array and then i will fix the first element and then i will use two pointer approach to find the other two elements. I will calculate the sum of three elements and find the difference between the target and the threesum. if the difference is less than the minimum difference then i will update the minimum difference and the three sum closest to the sum of three values threesum. If the threesum is greater than the target then i will move the right pointer to left otherwise i will move the left pointer to right. Finally, i will return the the sum of the three integers.
// TC : O(nlogn + n^2) = O(n^2)
// SC : O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int threeSumClosest = 0;
        int minDifference = INT_MAX;
        for (int i=0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            while (j < k){
                int threeSum = nums[i] + nums[j] + nums[k];
                int difference = abs(target - threeSum);
                if (difference < minDifference){
                    minDifference = difference;
                    threeSumClosest = threeSum;
                }
                if (threeSum > target) {
                    k--;
                }else{
                    j++;
                }
            }
        }
        return threeSumClosest;
    }
};