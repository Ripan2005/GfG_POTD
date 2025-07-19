class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        map<char,int> mp;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i]=='u')
            {
                mp[s[i]]++;
            }
        }
        if(!mp.size())return 0;
        
        int cnt = mp.size();
        int ans = 1;
        for(int i=1;i<=cnt;i++)ans*=i;
        for(auto i: mp)ans*=i.second;
        
        return ans;
    }
};
