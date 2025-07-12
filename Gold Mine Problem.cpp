class Solution {
  public:
    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = mat.size(), m = mat[0].size();
        if (i < 0 || i >= n || j >= m) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int dir1 = solve(i - 1, j + 1, mat, dp);
        int dir2 = solve(i, j + 1, mat, dp);
        int dir3 = solve(i + 1, j + 1, mat, dp);
        return dp[i][j] = mat[i][j] + max({dir1, dir2, dir3});
    }
    int maxGold(vector<vector<int>>& mat) {
        // code here
         int n = mat.size(), m = mat[0].size(), res = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
            res = max(res, solve(i, 0, mat, dp));
        return res;
    }
};
