class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        vector<int>freq(26,0);
        int unique =0, maxi=-1;
        for(int i=0,j=0 ; j<s.size();j++){
            freq[s[j]-'a']++;
            if(freq[s[j]-'a']==1) unique++;
            while(unique>k){
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0) unique--;
                i++;
            }
            if(unique==k) maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};
