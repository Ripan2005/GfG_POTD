//C++ CODE :
🧾 Problem Statement
Given a string s of lowercase letters and an integer k, count all substrings that contain exactly k distinct characters.

Examples:
• Input: s = "abc", k = 2 → Output: 2 → ["ab", "bc"]
• Input: s = "aba", k = 2 → Output: 3 → ["ab", "ba", "aba"]
• Input: s = "aa", k = 1 → Output: 3 → ["a", "a", "aa"]
  
class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here.
        int n      = s.length();
        int result = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);     // frequency array to store character counts
            int         distinctCnt = 0; // number of distinct characters in current window
            for (int j = i; j < n; j++) {
                if (freq[s[j] - 'a'] == 0) {
                    distinctCnt++;  // new distinct character found
                }
                freq[s[j] - 'a']++; // increment frequency of current character
                if (distinctCnt == k) {
                    result++; // valid substring with exactly k distinct characters
                } else if (distinctCnt > k) {
                    break;    // more than k distinct characters, break early
                }
            }
        }
        return result;
    }
};
