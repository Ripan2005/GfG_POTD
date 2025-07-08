class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n=arr.size();
       vector<int>ans(n,-1);
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
           mp[arr[i]]++;
       }
       stack<int>st;
       for(int i=n-1;i>=0;i--){
           while(!st.empty()&&mp[arr[i]]>=mp[st.top()]){
               st.pop();
           }
           if(!st.empty()){
              ans[i]=st.top();
           }
           st.push(arr[i]);
       }
       return ans;
    }
};
