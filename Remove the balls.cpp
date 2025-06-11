//C++ CODE
class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // CodeGenius
        stack<int> st;
        int n=color.size();
        for(int i=0;i<n;i++){
            if( !st.empty() && color[i]==color[st.top()] && radius[i]==radius[st.top()] ) st.pop();
            
            else st.push(i);
        }
        return st.size();
        
    }
};
