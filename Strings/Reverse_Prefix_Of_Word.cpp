// LEETCODE - 2000 Reverse Prefix of Word

// BRUTE FORCE APPROACH
// We can use stack to reverse the prefix of the word until we find the character ch. We push characters into stack until we find ch. Once we find ch, we pop characters from stack and replace them in the original string until stack is empty. Finally, we return the modified string.
// n is length of string
// TC : O(2n) = O(n)
// SC : O(n)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> s;
        int n = word.length();

        for (int i = 0; i < n; i++) {
            s.push(word[i]);
            if (word[i] == ch) {
                int j = 0;
                while (!s.empty()) {
                    word[j++] = s.top();
                    s.pop();
                }
                break;
            }
        }
        return word;
    }
};


// OPTIMAL APPROACH
// I am taking two pointers, one at the start of the string and another at the end where the character ch is found. Then I am swapping the characters at these two pointers and moving the start pointer forward and end pointer backward until they meet or cross each other. Finally, I return the modified string.
// n is the lengt of the string
// TC : O(n + n/2) = O(n)
// SC : O(1)
class Solution {
public:
    void swap(char &a, char &b) {
        char temp = a;
        a = b;
        b = temp;
    }

    void reverse(string &word, int start, int end){
        while (start < end){
            swap(word[start++],word[end--]);
        }
    }

    string reversePrefix(string word, char ch) {
        int n = word.length();
        int start = 0;
        int end = 0;

        while (end < n){
            if (word[end] == ch) {
                reverse(word, start, end);
                break;
            }
            end++;
        }
        return word;
    }
};