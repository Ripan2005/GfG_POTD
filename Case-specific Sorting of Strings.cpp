class Solution {
  public:
    string caseSort(string& s) {
        // code here
        vector<int>f1(26,0),f2(26,0);
        for(auto&c:s){
            if(isupper(c))f2[c-'A']++;
            else f1[c-'a']++;
        }
        int s1=0,s2=0,i=0;
        string result;
        while(i<s.size()){
            if(isupper(s[i])){
                while(f2[s2]==0)s2++;
                result+=s2+'A';
                f2[s2]--;
            }
            else{
                while(f1[s1]==0)s1++;
                result+=s1+'a';
                f1[s1]--;
            }
            i++;
        }
        return result;
    }
};
