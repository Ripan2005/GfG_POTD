class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        int total=0,maxlen=1,LisSum=INT_MAX;
        vector<int>len(n,1),sum(n);
        
        for(int i=0;i<n;i++) total+=arr[i];
        
        for(int i=0;i<n;i++){
            sum[i]=arr[i];
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i] && len[j]+1>=len[i]){
                    len[i]=len[j]+1;
                    sum[i]=sum[j]+arr[i];
                }
            }
            maxlen=max(maxlen,len[i]);
        }
        for(int i=0;i<n;i++){
            if(len[i]==maxlen){
                LisSum=min(LisSum,sum[i]);
            }
        }
        return total-LisSum;
    }
};
