 /* Sum-string
Difficulty: HardAccuracy: 50.56%Submissions: 40K+Points: 8
Given a string s consisting of digits, determine whether it can be classified as a sum-string.

A sum-string is a string that can be split into more than two non-empty substrings such that:


The rightmost substring is equal to the sum of the two substrings immediately before it (interpreted as integers).

This condition must apply recursively to the substrings before it.

The rightmost substring (and any number in the sum) must not contain leading zeroes, unless the number is exactly '0'.

Examples:

Input: s = "12243660"
Output: true
Explanation: The string can be split as {"12", "24", "36", "60"} where each number is the sum of the two before it:
36 = 12 + 24, and 60 = 24 + 36. Hence, it is a sum-string.
Input: s = "1111112223"
Output: true
Explanation: Split the string as {"1", "111", "112", "223"}, where:
112 = 1 + 111 and 223 = 111 + 112. Hence, it follows the sum-string rule.
Input: s = "123456"
Output: false
Explanation: There is no valid split of the string such that each part satisfies the sum-string property recursively.
Constraints:
1 ≤ s.size() ≤ 100
String consists of characters from '0' to '9'.
 */  
/************************************************************ C++ ************************************************/
class Solution {
  public:
      // Adds two numeric strings and returns the sum as string
    string addStrings(string& num1, string& num2) {
        // Ensure num1 is the longer string to simplify remaining digit addition
        if (num1.length() < num2.length()) {
            swap(num1, num2);
        }

        int    len1  = num1.length();
        int    len2  = num2.length();
        string sum   = "";
        int    carry = 0;

        // Add digits from right to left (least significant to most)
        for (int i = 0; i < len2; i++) {
            int d1    = num1[len1 - 1 - i] - '0'; // digit from num1
            int d2    = num2[len2 - 1 - i] - '0'; // digit from num2
            int digit = (d1 + d2 + carry) % 10;   // resulting digit
            carry = (d1 + d2 + carry) / 10;       // carry for next addition
            sum   = char(digit + '0') + sum;      // prepend digit to sum
        }

        // Add remaining digits from num1 (if any)
        for (int i = len2; i < len1; i++) {
            int d     = num1[len1 - 1 - i] - '0';
            int digit = (d + carry) % 10;
            carry = (d + carry) / 10;
            sum   = char(digit + '0') + sum;
        }

        // If carry is left, add it to front
        if (carry) {
            sum = char(carry + '0') + sum;
        }

        return sum;
    }

    // Recursively checks if the string from index `start` is a valid sum-sequence
    bool checkSequence(string& s, int start, int len1, int len2) {
        string part1 = s.substr(start, len1);            // First number
        string part2 = s.substr(start + len1, len2);     // Second number
        string part3 = addStrings(part1, part2);         // Their sum

        int len3 = part3.length();

        // If the sum segment exceeds remaining length, return false
        if (start + len1 + len2 + len3 > s.length()) {
            return false;
        }

        // If the calculated sum matches the next substring in s
        if (part3 == s.substr(start + len1 + len2, len3)) {
            // If entire string is matched successfully
            if (start + len1 + len2 + len3 == s.length()) {
                return true;
            }
            // Recurse with new start, shifting by part1 length
            return checkSequence(s, start + len1, len2, len3);
        }
        // If sum doesn't match, return false
        return false;
    }
    // Main function to check if string is a valid sum-string
    bool isSumString(string &s) {
        // code here
        int n = s.length();
        // Try all possible combinations of lengths for first and second parts
        for (int len1 = 1; len1 < n; len1++) {
            for (int len2 = 1; len1 + len2 < n; len2++) {
                if (checkSequence(s, 0, len1, len2)) {
                    return true;
                }
            }
        }
        return false;
        
    }
};
