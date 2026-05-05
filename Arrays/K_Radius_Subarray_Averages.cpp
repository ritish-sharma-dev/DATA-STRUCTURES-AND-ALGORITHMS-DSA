// LEETCODE - 2090. K Radius Subarray Averages


// BRUTE FORCE APPROACH
// TC : O(n * n + 2k+1) 
// AS : O(1)
// SC : O(1)
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> ans(n, -1);
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                if (j-i+1 == 2*k+1){
                    int windowSum = 0;
                    for (int l=i; l<=j; l++){
                        windowSum += nums[l];
                    }
                    int average = windowSum / (2*k+1);
                    ans[i+(j-i)/2] = average;               
                }
            }
        }

        return ans;
    }
};



// BETTER THAN BRUTE FORCE APPROACH
// TC : O(n^2)
// AS : O(1)
// SC : O(1)
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> ans(n, -1);

        for (int i=0; i<n; i++){
            int windowSum = 0;
            for (int j=i; j<n; j++){
                windowSum += nums[j];
                if (j-i+1 == 2*k+1){
                    int average = windowSum / (2*k+1);
                    ans[i+(j-i)/2] = average;               
                }
            }
        }

        return ans;
    }
};


// BETTER APPROACH - SLIDING WINDOW + PREFIX SUM
// TC : O(2n) = O(n)
// AS : O(n)
// SC : O(n)
class Solution {
public:
    long long findWindowSum(int i, int j, vector <long long> &prefixSum){
        long long windowSum = 0;
        windowSum += prefixSum[j];
        windowSum -= (i!=0) ? prefixSum[i-1] : 0;
        return windowSum;
    }

    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> ans(n, -1);

        vector <long long> prefixSum(n, 0);
        long long sum = 0;
        for (int i=0; i<n; i++){
            sum += nums[i];
            prefixSum[i] = sum;
        }

        int windowLength = k + 1 + k;
        int i = 0;
        int j = windowLength - 1;
        while (j < n){
            long long windowSum = findWindowSum(i, j, prefixSum);
            long long average = windowSum / windowLength;
            ans[i+(j-i)/2] = average;
            i++;
            j++;
        }
        return ans;
    }
};


// OPTIMAL APPROACH - SLIDING WINDOW
// TC : O(n)
// AS : O(1)
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);

        int windowLength = k + 1 + k;
        int i = 0;
        int j = windowLength - 1;
        long long windowSum = 0;
        if (j < n) {
            for (int l = 0; l < windowLength; l++) {
                windowSum += nums[l];
            }
        }

        while (j < n) {
            long long average = windowSum / windowLength;
            ans[i + (j - i) / 2] = average;
            j++;
            if (j >= n) break;
            windowSum += nums[j];
            windowSum -= nums[i];
            i++;
        }
        return ans;
    }
};