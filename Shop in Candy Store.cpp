class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n = prices.size();
        sort(prices.begin(), prices.end());

        int minSum = 0, maxSum = 0;
        int i = 0, j = n - 1;

        while (i <= j) {
            minSum += prices[i];
            j -= k;
            i++;
        }

        i = 0;
        j = n - 1;
        while (i <= j) {
            maxSum += prices[j];
            i += k;
            j--;
        }

        return {minSum, maxSum};
    }
};
