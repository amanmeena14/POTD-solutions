class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        vector<int> v;
        for(int i=0;i<a.size();i++){
            v.push_back(a[i]);
        }
        for(int i=0;i<b.size();i++){
            v.push_back(b[i]);
        }
        sort(v.begin(),v.end());
        return v[k-1];
    }
};