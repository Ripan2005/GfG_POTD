/************************************************************ C++ ************************************************/
class Solution {
public:
    // Helper function to compare pattern with substring of text at index idx
    bool isMatch(string& txt, string& pat, int idx) {
        for (int i = 0; i < pat.size(); i++) {
            if (txt[idx + i] != pat[i]) {
                return false;
            }
        }
        return true;
    }
    vector<int> search(string& pat, string& txt) {
         // code here.
        int m = pat.size();  // Length of pattern
        int n = txt.size();  // Length of text

        int base = 26;       // Base for hash (26 lowercase letters)
        int mod  = 101;      // A prime modulus to avoid overflow and reduce collisions

        vector<int> result;
        int         patHash = 0; // Hash value for pattern
        int         txtHash = 0; // Rolling hash value for text
        int         power   = 1; // Power of base (base^i)

        // Compute initial hash for pattern and first window of text
        for (int i = m - 1; i >= 0; i--) {
            int patVal = pat[i] - 'a' + 1;
            int txtVal = txt[i] - 'a' + 1;

            patHash = (patHash + patVal * power) % mod;
            txtHash = (txtHash + txtVal * power) % mod;
            power   = (power * base) % mod;
        }

        // Compare first window hash
        if (txtHash == patHash && isMatch(txt, pat, 0)) {
            result.push_back(1); // Store 1-based index
        }

        // Precompute highest power for sliding window (base^(m-1))
        int highestPower = 1;
        for (int i = 1; i < m; i++) {
            highestPower = (highestPower * base) % mod;
        }

        // Slide window across text
        for (int i = 1; i <= n - m; i++) {
            int leftVal = txt[i - 1] - 'a' + 1;

            // Remove leftmost character from hash
            txtHash = (txtHash - (leftVal * highestPower) % mod + mod) % mod;
            txtHash = (txtHash * base) % mod;

            // Add new character to hash
            int newVal = txt[i + m - 1] - 'a' + 1;
            txtHash = (txtHash + newVal) % mod;

            // If hashes match, verify with character comparison
            if (txtHash == patHash && isMatch(txt, pat, i)) {
                result.push_back(i + 1); // Store 1-based index
            }
        }

        return result;
    }
};
