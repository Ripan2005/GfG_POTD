class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        int c = arr.size();
        int count = pow(10 - c, n - 1);
        int r = (9 - c) * count;
        for (int i = 0; i < c; i++) {
            if (arr[i] == 0) {
                r = (9 - c + 1) * count;
                break;
            }
        }

        int z = pow(10, n - 1);
        int j = 9 * z;
        int result = j - r;
        return result;
    }
};
