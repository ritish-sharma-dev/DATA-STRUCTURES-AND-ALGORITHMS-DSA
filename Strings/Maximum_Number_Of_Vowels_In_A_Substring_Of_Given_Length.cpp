// LEETCODE -  1456. Maximum Number of Vowels in a Substring of Given Length


// BRUTE FORCE APPROACH
// The question is that find the maximum number of vowels in a substring of length k. So, what i will do i will find out all the substrings. If the length of the substring is equal to k then check how many vowels are present in that substring and if the number of vowels in that substring is greater than the maximun number of vowels count then update the maximum number of vowels count to the number of vowels in that substring. Do this for all substrings of length k and finally, return the maximum number of vowels count.
// TC : O(n^2*k)
// SC : O(1)
class Solution {
public:
    bool characterIsAVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int maxVowelsCount = 0;
        for (int i = 0; i < n; i++) {
            int vowelsCount = 0;
            for (int j = i; j < n; j++) {
                if (j - i + 1 == k) {
                    for (int k = i; k <= j; k++) {
                        if (characterIsAVowel(s[k])) vowelsCount++;
                    }
                    if (vowelsCount > maxVowelsCount) {
                        maxVowelsCount = vowelsCount;
                    }
                }
            }
        }
        return maxVowelsCount;
    }
};

// Why the above approach is not optimal ?
// Because i am finding all the substrings and then check if there length is equal to k and then count the number of vowels in that substring. So, i am doing extra work. 
// If i only take the substrings whose length is equal to k then i can save so much time. So, i will use the sliding window approach of length k and then count the number of vowels in that window and check if the number of vowels in that window is greater than the maximum number of vowels count then update the maximum number of vowels count to the number of vowels in that window. and slide the window.  Do this for all windows of length k and finally, return the maximum number of vowels count.

// BETTER APPROACH - SLIDING WINDOW
// TC : O(n*k)
// SC : O(1)
class Solution {
public:
    bool characterIsAVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int maxVowelsCount = 0;

        int i = 0;
        int j = k - 1;
        while (j < n) {
            int vowelsCount = 0;
            for (int l = i; l <= j; l++) {
                if (characterIsAVowel(s[l]))
                    vowelsCount++;
            }
            if (vowelsCount > maxVowelsCount) {
                maxVowelsCount = vowelsCount;
            }
            i++;
            j++;
        }

        return maxVowelsCount;
    }
};

// Why the above approach is not optimal ?
// Because i am counting the number of vowels for each sliding window. So, i am doing extra work. If i only count the number of vowels for the first window and then for the next window i will check if the new character is a vowel or not and if it is a vowel then i will increment the vowels count and if the old character is a vowel then i will decrement the vowels count. So, i am doing less work. So, this approach is optimal.
// OPTIMAL APPROACH - SLIDING WINDOW
// TC : O(k + n)
// SC : O(1)
class Solution {
public:
    bool characterIsAVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int maxVowelsCount = 0;

        int i = 0;
        int j = k - 1;
        int vowelsCount = 0;
        for (int l = i; l <= j; l++) {
            if (characterIsAVowel(s[l])) vowelsCount++;
        }

        while (j < n) {
            if (vowelsCount > maxVowelsCount) {
                maxVowelsCount = vowelsCount;
                if (maxVowelsCount == k) break;
            }
            j++;
            if (j < n && characterIsAVowel(s[j])) vowelsCount++;
            if (i < n && characterIsAVowel(s[i])) vowelsCount--;
            i++;
        }

        return maxVowelsCount;
    }
};