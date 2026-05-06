// LEETCODE - 2653 - Sliding Subarray Beauty

// BRUTE FORCE APPROACH
// TC : O(n^3 log n)
// SC : O(k) = O(n) in worst case
class Solution {
public:
    int findKthMin(int i, int j, int x, vector <int> &nums){
        vector <int> subarray;
        int negativeCount = 0;
        for (int y=i; y<=j; y++){
            if (nums[y] < 0) negativeCount++;
            subarray.push_back(nums[y]);
        }
        sort(subarray.begin(), subarray.end());
        return (negativeCount < x) ?  0 : subarray[x-1];
    }
    
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector <int> res(n-k+1, 0);

        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                if (j-i+1 == k){
                    int kthMin = findKthMin(i, j, x, nums);
                    res[i] = kthMin;
                }
            }
        }
        return res;
    }
};


// OPTIMAL APPROACH
// TC : O(n)
// SC : O(1)
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector <int> res;
        vector <int> freq(101, 0);

        int i = 0;
        int j = k-1;
        int negativeValues = 0;
        for (int l=0; l<k; l++){
            freq[50+nums[l]]++;
            if (nums[l] < 0) negativeValues++;
        }

        while (j < n){
            if (negativeValues < x){
                res.push_back(0);
            }else{
                int minCount = 0;
                for (int m=0; m<101; m++){
                    if (freq[m] != 0){
                        minCount += freq[m];
                    }

                    if (x > minCount-freq[m] && x <= minCount){
                        res.push_back(m-50);
                        break;
                    }
                }
            }

            j++;
            if (j>=n) break;
            freq[50+nums[j]]++;
            if (nums[j] < 0) negativeValues++;
            freq[50+nums[i]]--;
            if (nums[i] < 0) negativeValues--;
            i++;
        }

        return res;
    }
};