class Solution {
  public:
    vector<int> solve(vector<int>& arr,int i,int last,vector<vector<vector<int>>> &dp){
        //base case
        if(i==arr.size()) return {};
        
        if(!dp[i][last+1].empty()) return dp[i][last+1];
        //recursive case
        auto take=(last==-1 || arr[i]%arr[last]==0) ? solve(arr,i+1,i,dp) :vector<int>{};
        if(last==-1 || arr[i]%arr[last]==0) take.insert(take.begin(),arr[i]);
        auto nottake=solve(arr,i+1,last,dp);
        
        return dp[i][last+1]=(nottake.size()>take.size() || (nottake.size()==take.size() && nottake>take ))? nottake : take;
    }
    vector<int> largestSubset(vector<int>& arr) {
        // CodeGenius
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1));
        return solve(arr,0,-1,dp);
        
    }
};
