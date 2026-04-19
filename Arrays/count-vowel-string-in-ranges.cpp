// LEETCODE - 2559 - Count Vowel Strings in Ranges


// BRUTE FORCE APPROACH
// We will iterate through the queries and for each query we will iterate through the words and check if the first and last character of the word is a vowel or not. If it is a vowel then we will increment the count and at the end of the query we will push the count in the solution vector and return it at the end.
// m is the size of words and n is the size of queries
// TC : O(n*m)
// SC : O(n) (only used for returning the output)
// AS : O(1)
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int m = words.size();
        int n = queries.size();
        vector <int> sol;

        for (int i=0; i<n; i++){
            int start = queries[i][0];
            int end = queries[i][queries[i].size()-1];
            int  count = 0;
            for (int j=start; j<=end; j++){
                char startingChar = words[j][0];
                char endingChar = words[j][words[j].size()-1];
                if ( (startingChar == 'a' || startingChar == 'e' || startingChar == 'i' || startingChar == 'o' || startingChar == 'u') && (endingChar == 'a' || endingChar == 'e' || endingChar == 'i' || endingChar == 'o' || endingChar == 'u')){
                    count++;
                }
            }

            sol.push_back(count);
        }

        return sol;
    }
};


// OPTIMIZED APPROACH
// We will create a prefix sum array where we will store the count of vowel strings whose first and last character is a vowel. Then we will iterate through the queries and for each query we will check the count of vowel strings in the range of the query by using the prefix sum array. If the start index of the query is 0 then we will directly push the count at the end index of the query in the solution vector otherwise we will subtract the count at the start index - 1 from the count at the end index and push it in the solution vector and return it at the end.
// m is the size of words and n is the size of queries
// TC : O(m + n)
// SC : O(m + n)
// AS : O(m)
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int m = words.size();
        int n = queries.size();
        vector <int> sol;
        vector <int> prefix;
        int count = 0;
        for (int i = 0; i < m; i++) {
            char startingChar = words[i][0];
            char endingChar = words[i][words[i].size() - 1];
            if ((startingChar == 'a' || startingChar == 'e' ||
                 startingChar == 'i' || startingChar == 'o' ||
                 startingChar == 'u') &&
                (endingChar == 'a' || endingChar == 'e' || endingChar == 'i' ||
                 endingChar == 'o' || endingChar == 'u')) {
                count++;
            }
            prefix.push_back(count);
        }

        for (int j=0; j<n; j++){
            int start = queries[j][0];
            int end = queries[j][1];
            if (start != 0){
                sol.push_back(prefix[end] - prefix[start-1]);
            }else{
                sol.push_back(prefix[end]);
            }
        }

        return sol;
    }
}
;