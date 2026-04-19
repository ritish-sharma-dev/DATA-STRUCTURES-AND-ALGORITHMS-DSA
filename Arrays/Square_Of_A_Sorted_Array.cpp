// LEETCODE - 977. Squares of a Sorted Array

//BRUTE FORCE APPROACH
// I can iterate through the array and put the sqares of the elements in the same array and then i sort the array and return it
// n is the length of array
// TC : O(n + nlogn) = O(nlogn)
// SC : O(1) (ignoring the recursion stack)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++){
            nums[i] = nums[i]*nums[i];
        }

        sort(nums.begin(),nums.end());
        return nums;
    }
};


// OPTIMIZED APPROACH
// I am simply using two pointers approach
// I put negative values square in one array and positive values square in another array then i observe that the values in positive array are sorted and values in negative array are also sorted in reverse order so i will simply merge these two sorted arrays using two pointers approach and return the merged array
// n is the length of nums
// TC : O(2n) = O(n)
// SC : O(n)
class Solution {
public:
    vector <int> mergeTwoSortedArrays(vector <int> posSquare, vector <int> negSquare){
        vector <int> ans;

        int i = 0;
        int j = negSquare.size()-1;

        while (i < posSquare.size() && j >= 0){
            if (posSquare[i] < negSquare[j]){
                ans.push_back(posSquare[i++]);
            }else{
                ans.push_back(negSquare[j--]);
            }
        }

        while (i < posSquare.size()){
            ans.push_back(posSquare[i++]);
        }

        while (j >= 0){
            ans.push_back(negSquare[j--]);
        }
        return ans;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector <int> posSquare;
        vector <int> negSquare;

        for (int i=0; i<n; i++){
            if (nums[i] < 0){
                negSquare.push_back(nums[i]*nums[i]);
            }else{
                posSquare.push_back(nums[i]*nums[i]);
            }
        }

        nums = mergeTwoSortedArrays(posSquare, negSquare);

        return nums;
    }
};