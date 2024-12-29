class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        set<int> st;
        vector<int> res;
        for(int i=0;i<a.size();i++){
            st.insert(a[i]);
        }
        for(int j=0;j<b.size();j++){
            if(st.find(b[j])!=st.end()){
                res.push_back(b[j]);
                st.erase(b[j]);
            }
        }
        return res;
    }
};