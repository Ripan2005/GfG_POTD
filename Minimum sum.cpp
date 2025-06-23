Class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        string str1 ="";
        string str2 ="";
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                if(arr[i] != 0){
                    str1 += arr[i] + '0';
                }
            }
            else{
                if(arr[i] != 0){
                    str2 += arr[i] + '0';
                }
            }
        }
        int i=str1.length() - 1;
        int j = str2.length() -1;
        int carry = 0;
        string ans ="";
        
        while(i>=0 || j>=0 || carry){
            int d1 = (i>=0) ? str1[i--] - '0' : 0;
            int d2 = (j>=0) ? str2[j--] -'0' : 0;
            
            int sum = d1+d2+carry;
            
            carry = sum/10;
            
            ans += (sum%10) + '0';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
