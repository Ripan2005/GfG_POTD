/*
 *
 * Dry Run
 *
 * Let s = "abca"
 * n = 4
 * set = {}
 *
 * i = 0, j = 1:
 *   swap(s[0], s[1]) → s = "baca"
 *   set.insert("baca") → set = {"baca"}
 *   swap back → s = "abca"
 *
 * i = 0, j = 2:
 *   swap(s[0], s[2]) → s = "cbaa"
 *   set.insert("cbaa") → set = {"baca","cbaa"}
 *   swap back → s = "abca"
 *
 * i = 0, j = 3:
 *   swap(s[0], s[3]) → s = "abca" (same)
 *   set.insert("abca") → set = {"baca","cbaa","abca"}
 *   swap back → s = "abca"
 *
 * i = 1, j = 2:
 *   swap(s[1], s[2]) → s = "acba"
 *   set.insert("acba") → set = {"baca","cbaa","abca","acba"}
 *   swap back → s = "abca"
 *
 * i = 1, j = 3:
 *   swap(s[1], s[3]) → s = "aacb"
 *   set.insert("aacb") → set = {"baca","cbaa","abca","acba","aacb"}
 *   swap back → s = "abca"
 *
 * i = 2, j = 3:
 *   swap(s[2], s[3]) → s = "abac"
 *   set.insert("abac") → set = {"baca","cbaa","abca","acba","aacb","abac"}
 *   swap back → s = "abca"
 *
 * Final set size = 6
 */
/************************************************************ C++ ************************************************/


class Solution {
  public:
    int countStrings(string &s) {
        // code here
        int n = s.length();

        vector<int> mp(26, 0);         // frequency array for lowercase letters
        int         result = 0;

        for (int i = 0; i < n; i++) {
            result += (i - mp[s[i] - 'a']);   // count swaps with different chars seen so far
            mp[s[i] - 'a']++;                 // increment frequency of current character
        }

        for (int i = 0; i < 26; i++) {
            if (mp[i] > 1) {         // check if any character has duplicate
                result++;            // if yes, add one for swap that returns same string
                break;
            }
        }

        return result;
    }
};
