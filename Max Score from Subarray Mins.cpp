class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int ans=0;
        for(int i =1;i<arr.size();i++)
            ans=max(ans,arr[i]+arr[i-1]);
        return ans;
    }
};
