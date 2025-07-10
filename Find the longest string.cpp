class Solution {
public:
    string longestString(vector<string>& arr) {
        // code here
        sort(arr.begin(), arr.end()); // Sort lexicographically
        unordered_set<string> valid;
        valid.insert(""); // base case
        string res = "";

        for (string& word : arr) {
            string prefix = word.substr(0, word.length() - 1);
            if (valid.count(prefix)) {
                valid.insert(word);
                if (word.length() > res.length() || 
                    (word.length() == res.length() && word < res)) {
                    res = word;
                }
            }
        }

        return res;
    }
