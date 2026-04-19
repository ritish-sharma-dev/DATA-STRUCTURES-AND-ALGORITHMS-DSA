// LEETCODE - 2022  Convert 1D Array Into 2D Array

class Solution {
public:
    // OPTIMAL APPROACH
    // m is no of rows, n is no of cols and x is length of original array
    // TC : O(m*n) = O(x)
    // SC : O(m*n) = O(x)
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int lenOf1DArray = original.size();
        int lenOf2DArray = m*n;
        if (lenOf2DArray != lenOf1DArray) return {};

        vector<vector<int>> twoDArray(m, vector <int> (n,0));
        int index = 0;
        while (index < lenOf1DArray){
            int row = index / n;
            int col = index % n;
            twoDArray[row][col] = original[index];
            index++;
        }
        return twoDArray;
    }
};