// LEETCODE - 567. Permutation in String


// OPTIMIZED APPROACH - SLIDING WINDOW + FREQUENCY ARRAY
// This Question is similar to 438. Find All Anagrams in a String
// n1 is length of s1
// n2 is length of s2
// TC : O(n1 + n2)
// SC : O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n2 < n1) return false;

        vector <int> s1Freq(26, 0);
        vector <int> s2Freq(26, 0);

        for (int i=0; i<n1; i++){
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }

        int i = 0;
        int j = n1 - 1;
        while (j < n2){
            if (s1Freq == s2Freq) return true;
            j++;
            if (j < n2) {
                s2Freq[s2[j] - 'a']++;
                s2Freq[s2[i] - 'a']--;
                i++;
            }
        }

        return false;
    }
};