class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n      = a1.size();
        int result = 0;                // stores the maximum length found so far

        // Check all possible subarrays by choosing start index i
        for (int i = 0; i < n; i++) {
            int sum1 = 0;              // cumulative sum of a1 from i to j
            int sum2 = 0;              // cumulative sum of a2 from i to j

            // Extend the subarray to end index j
            for (int j = i; j < n; j++) {
                // Accumulate sums for current subarray [i..j]
                sum1 += a1[j];
                sum2 += a2[j];

                // If the two sums match, update result with current span length
                if (sum1 == sum2) {
                    result = max(result, j - i + 1);
                }
            }
        }

        return result;
    }
};
