// LEETCODE - 1876. Substrings of Size Three with Distinct Characters


// OPTIMAL APPROACH
// TC : O(n)
// AS : O(1)
// SC : O(1)
class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        if (n < 3) return 0;

        int count = 0;
        for (int i = 0; i < n-2; i++) {
            char a = s[i];
            char b = s[i + 1];
            char c = s[i + 2];

            if (a!=b && b!=c && c!=a){
                count++;
            }
        }
        return count;
    }
    };