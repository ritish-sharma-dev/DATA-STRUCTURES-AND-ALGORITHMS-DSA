// LEETCODE - 1343 : Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold



// BETTER SOLUTION : SLIDING WINDOW + PREFIX SUM
// Question is already said that we want a subarray of size k, so we can directly use the sliding window technique to find the all subarrays of size k and i also want to find the sum of all the subarrays of size k, so we can use the prefix sum to find the sum of all the subarrays of size k in O(1) time, by precomputing the prefix sum of the array, we can find the sum of any subarray in O(1) time, with the help of prefix sum, we can find the sum of all the subarrays of size k in O(n) time, and then we can find the average of all the subarrays of size k and check if it is greater than or equal to threshold, if it is then we can increment the count, and finally we can return the count.
// TC : O(n + (n-k)) = O(n-k) = O(n)
// AS : O(n)
// SC : O(n)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();

        vector <int> prefixSum;
        int sum = 0;
        for (int x : arr){
            sum += x;
            prefixSum.push_back(sum);
        }

        int i = 0;
        int j = k-1;
        int count = 0;
        while (j < n){
            double windowSum = 0;
            windowSum += prefixSum[j];
            windowSum -= (i!=0) ? prefixSum[i-1] : 0;
            double average = windowSum/k;
            if (average >= threshold) count++;
            i++;
            j++;
        }
        return count;
    }
};

// Why the optimal solution is better than the better solution ?
// The optimal solution has a space complexity of O(1) while the better solution has a space complexity of O(n) due to the prefix sum array.
// In the optimal solution, we are directly calculating the sum of the current window by adding the new element and removing the old element, which takes O(1) time. In the better solution, we are using the prefix sum array to calculate the sum of the current window, which also takes O(1) time, but we have to precompute the prefix sum array which takes O(n) time and O(n) space. Therefore, the optimal solution is more efficient in terms of space complexity and also has a better time complexity than the better solution.
// OPTIMAL SOLUTION : SLIDING WINDOW
// TC : O(k + n - k) = O(n)
// AS : O(1)
// SC : O(1)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();

        int i = 0;
        int j = k-1;
        int count = 0;
        double windowSum = 0;
        for (int l=i; l<=j; l++){
            windowSum += arr[l];
        }

        while (j < n){
            double average = windowSum/k;
            if (average >= threshold) count++;
            j++;
            if (j < n) windowSum += arr[j];
            if (i < n) windowSum -= arr[i];
            i++;
        }
        return count;
    }
};