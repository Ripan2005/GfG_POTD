class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>sorted_b(100001,0);
        for(int i=0;i<b.size();i++) sorted_b[b[i]]++;
        
        for(int i=1;i<100001;i++) sorted_b[i]+=sorted_b[i-1];
        vector<int>ans(a.size());
        for(int i=0;i<a.size();i++)
            ans[i]=sorted_b[a[i]];
        return ans;
    }
};
