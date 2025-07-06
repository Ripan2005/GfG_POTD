class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size();
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>vis;
        
        pq.push({a[0]+b[0],{0,0}});
        vis.insert({0,0});
        vector<int> ans;
        while(ans.size()<k){
            auto top=pq.top();
            pq.pop();
            
            int sum=top.first;
            int i=top.second.first;
            int j=top.second.second;
            ans.push_back(sum);
            
            if(i<n-1&& vis.find({i+1,j})==vis.end()){
                pq.push({a[i+1]+b[j],{i+1,j}});
                vis.insert({i+1,j});
            }
            if(j<n-1&& vis.find({i,j+1})==vis.end()){
                pq.push({a[i]+b[j+1],{i,j+1}});
                vis.insert({i,j+1});
            }
        }
        return ans;
    }
};
