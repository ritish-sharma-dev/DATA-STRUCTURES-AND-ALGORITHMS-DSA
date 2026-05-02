// Leetcode - 238. Product of Array Except Self



// BRUTE FORCE APPROACH
// we are using nested loops first loop is for iterating through each element and second loop is for calculating the product of all the elements except the current element. We are checking if the current index is equal to the inner loop index, if it is then we are skipping that element and multiplying the rest of the elements. Finally, we are storing the product in the answer array and returning it.
// TC : O(n^2)
// SC : O(1) (do not considering the result array)
// AS : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> answer(n);
        for (int i=0; i<n; i++){
            int product = 1;
            for (int j=0; j<n; j++){
                if (i == j) continue;
                product *= nums[j];
            }
            answer[i] = product;
        }
        return answer;
    }
};


// BETTER APPROACH
// The intuition behind this approach is when i want to find the product except self if i remove the current element from the product of all the elements then i will observe that product is divided into two part left and right if i can find the product of left and right part then i can easily find the product except self by multiplying the left product and the right product and put it in the answer array at the index of the current element.
// What i will do is when i will traverse the array from left to right i will keep multiplying the elements and and getting the left product but how will i get the right product ? for that i will use the suffix product array where i will store the product of the elements from right to left and when i will traverse the array from left to right i can easily get the right product from the suffix product array and multiply it with the left product to get the answer for that index and then update the left product by multiplying it with the current element and move to the next index.
// TC : O(2n) = O(n)
// AS : O(n)
// SC : O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> answer(n);

        vector <int> suffixProduct(n);
        int product = 1;
        for (int i=n-1; i>=0; i--){
            product *= nums[i];
            suffixProduct[i] = product;
        }

        int leftProduct = 1;
        for (int i=0; i<n; i++){
            int rightProduct = (i+1 < n) ? suffixProduct[i+1] : 1;
            answer[i] = leftProduct *  rightProduct;
            leftProduct *= nums[i];
        }

        return answer;
    }
};


// OPTIMAL APPROACH
// This intution is same as the better approach but we are not using the suffix product array instead what we are doing is we firstly we are calculating the left product and storing it in the answer array and then we are calculating the right product while traversing from right to left and multiplying it with the left product which is already stored in the answer array. In this way we are able to calculate the product except self without using any extra space.
// TC : O(2n) = O(n)
// AS : O(1)
// SC : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> answer(n);

        int leftProduct = 1;
        for (int i=0; i<n; i++){
            answer[i] = leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;
        for (int i=n-1; i>=0; i--){
            answer[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return answer;
    }
};
