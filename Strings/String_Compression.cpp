// LEETCODE - 443 String Compression

// BRUTE FORCE APPROACH
// I am traversing the array and counting the frequency of each character and adding the character and its frequency to a string. Finally, I am replacing the original array with the characters of the compressed string and returning the length of the compressed string.
// n is length of chars
// TC : O(n + n) = O(2n) = O(n)
// SC : O(n)
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string compressStr = "";

        int i=0;
        while (i < n){
            char ch = chars[i];
            int chFreqCount = 0;
            while (i < n && chars[i] == ch){
                chFreqCount++;
                i++;
            }
            compressStr += ch;
            if (chFreqCount != 1){
                compressStr += to_string(chFreqCount);
            }
        }

        int j = 0;
        int m = compressStr.length();
        while (j < m){
            chars[j] = compressStr[j];
            j++;
        }

        return m;
    }
};


// OPTIMAL APPROACH
// I am traversing the array and counting the frequency of each character and adding the character and its frequency to the original array. Finally, I am returning the length of the compressed string.
 // n is length of chars
// TC : O(n)
// SC : O(1)
class Solution {
public:
    void reverseRange(vector <char> &chars, int start, int end){
        while (start < end){
            swap(chars[start++], chars[end--]);
        }
    }

    int compress(vector<char>& chars) {
        int n = chars.size();

        int i=0;
        int j = 0;
        while (i < n){
            char ch = chars[i];
            int count = 0;
            while (i < n && chars[i] == ch){
                count++;
                i++;
            }

            chars[j++] = ch;
            if (count != 1){
                int start = j;
                while (count > 0){
                    int value = count % 10;
                    chars[j++] = value + '0';
                    count /= 10;
                }
                reverseRange(chars, start, j-1);
            }
            
        }
        return j;
    }
};