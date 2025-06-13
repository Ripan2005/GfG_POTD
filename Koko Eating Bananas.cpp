class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int maxi = INT_MIN;
        for(auto z : arr){
            maxi = max(maxi, z);
        }
        int ans = -1;
        return fun(1, maxi, arr, k, ans);
    }
    int fun(int l, int r, vector<int> &arr, int &k, int &ans){
        if(l>=r){
            return r;
        }
        int m = l + (r-l)/2;
        
        int count = 0;
        for(auto z : arr){
            count += (z/m);
            if(z%m)
                count++;
        }
        if(count > k)
            return fun(m+1, r, arr, k, ans);
        return fun(l, m, arr, k, ans);
    }
};
