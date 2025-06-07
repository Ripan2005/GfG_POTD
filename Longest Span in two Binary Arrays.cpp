class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        vector<int>temp(a1.size());
        
        for(int i=0;i<a1.size();i++){
            temp[i]=a1[i]-a2[i];
        }
        int ans =0 ;
        int rem =0 ;
        map<int,int>mp;
        for(int i=0;i<temp.size();i++){
            rem+=temp[i];
            if(rem == 0){
                ans = max(i+1,ans);
            }
            if(mp.find(rem)!=mp.end()){
                ans = max(ans,i-mp[rem]);
            }
            if(mp.find(rem)==mp.end()){
                mp[rem] = i;
            }
        }
        return ans;
    }
};
