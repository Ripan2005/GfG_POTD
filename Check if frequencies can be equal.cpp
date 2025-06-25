class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int>freq(26,0);
        for(char c : s) freq[c-'a']++;
        
        unordered_map<int,int>mp;
        for(char f: freq) if(f)mp[f]++;
        
        if(mp.size()==1) return true;
        if(mp.size() !=2) return false;
        
        auto it = mp.begin();
        int F1=it->first ,c1=it->second;
        it++;
        int F2=it->first ,c2=it->second;
        if((F1==1 && c1==1) || (F2==1 && c2==1)) return true;
        if((abs(F1-F2)==1) && ((F1>F2 && c1==1) || (F2>F1 && c2==1))) return true;
        
        return false;
    }
};
