// LEETCODE - 442 Find All Duplicates in an Array

// BRUTE FORCE APPROACH
// we will run two loops and count the frequency of each element in the array and if the frequency is 2 then we will add that element to our answer vector.
// TC : O(N^2) 
// SC : O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        int n = nums.size();
        for (int i=0; i<n; i++){
            int count = 0;
            for (int j=i; j<n; j++){
                if (nums[i] == nums[j]){
                    count++;
                }
            }

            if (count == 2){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};



// BETTER APPROACH
// I am using hashmap to store the frequency of each element in the array . What i will do traverse the whole array and add the frequency of each element in the hashmap and after that i will traverse the hashmap and check if the frequency of any element is greater than 1 then i will add that element to my answer vector.
// TC : O(2n) = O(n)
// SC : O(n)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        int n = nums.size();
        unordered_map <int, int> m;
        for (int i=0; i<n; i++){
            m[nums[i]]++;
        }

        for (auto x : m){
            if (x.second > 1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};


// OPTIMAL APPROACH
// I am traversing the array two times. In the first traversal i will check if the element at index i is at its correct position or not if it is not at its correct position then i will swap it with the element at its correct position and if it is at its correct position then i will move to the next index. After the first traversal all the elements will be at their correct position except the duplicate elements. In the second traversal i will check if the element at index i is at its correct position or not if it is not at its correct position then i will add that element to my answer vector. 
// TC : O(2n) = O(n)
// SC : O(n)
// AS : O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        int n = nums.size();

        int i = 0;
        while (i < n){
            if (i+1 != nums[i] && nums[nums[i]-1] != nums[i]){
               swap(nums[i],nums[nums[i]-1]);
            }else{
                i++;
            }
        }

        i = 0;
        while (i < n){
            if (i+1 != nums[i]){
                ans.push_back(nums[i]);
            }
            i++;
        }

        return ans;
    }
};
