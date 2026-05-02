LEETCODE - 438. Find All Anagrams in a String


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector <int> answer;

        if (m < n) return answer;
        unordered_map <char, int> mp1;
        for (char x : p){
            mp1[x]++;
        }

        int i = 0;
        int j = n - 1;
        while (j < m){
            unordered_map <char, int> mp2;
            for (int k=i; k<=j; k++){
                mp2[s[k]]++;
            }

            bool equalOccurances = true;
            for (auto x : mp1){
                if (mp2.find(x.first) == mp2.end() || x.second != mp2[x.first]){
                    equalOccurances = false;
                }
            }
            if (equalOccurances) answer.push_back(i);
            i++;
            j++;
        }

        return answer;
    }
};



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector <int> answer;

        if (m < n) return answer;
        int mp1[26] = {0};
        for (char x : p){
            mp1[x-97] += 1;
        }

        int i = 0;
        int j = n - 1;
        while (j < m){
            int mp2[26] = {0};
            for (int k=i; k<=j; k++){
                mp2[s[k]-97] += 1;
            }

            bool equalOccurances = true;
            for (char x : p){
                if (mp1[x-97] != mp2[x-97]){
                    equalOccurances = false;
                }
            }
            if (equalOccurances) answer.push_back(i);
            i++;
            j++;
        }

        return answer;
    }
};


// OPTIMAL APPROACH
// I want to find the staring index of all the anagrams of p in s. The intuition is that if there is anagram of p in s, then it should have the same length as of size of p. Now i know that i want all substrings whose length is equal to size of p. what i will do i will use sliding window of size of p and now there is a problem i also want to check that the frequency of each character in the substring is same as frequency of each character in p. So i will do this this with the help of hashing but only array hashing because it take constant time to check the frequency of each character in the substring and p. If the array store the frequency of each character in the substring and array which store the frequency of each character in p are same then i will add the starting index of the substring to the answer. Now i will keep on sliding the window and and updating the frequency of each character in the substring and checking if the frequency of each character in the substring and p are same or not. If they are same then i will add the starting index of the substring to the answer. Finally i will return the answer.
// TC : O(n + m)
// SC : O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<int> answer;

        if (m < n) return answer;
        int mp1[26] = {0};
        for (char x : p) {
            mp1[x - 97] += 1;
        }

        int i = 0;
        int j = n - 1;
        int mp2[26] = {0};
        for (int k=i; k<=j; k++){
            mp2[s[k]-97] += 1;
        }

        while (j < m) {
            bool equalOccuraces = true;
            for (int l=0; l<26; l++){
                if (mp1[l] != mp2[l]){
                    equalOccuraces = false;
                    break;
                }
            }
            if (equalOccuraces) answer.push_back(i);
            j++;
            if (j < m) mp2[s[j]-97] += 1;
            mp2[s[i]-97] -= 1;
            i++;
        }

        return answer;
    }
};