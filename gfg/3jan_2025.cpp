class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long xo=0,ans=0;
        unordered_map<long,long> mp;
        mp[xo]=1;
        for(int i=0;i<arr.size();i++){
            xo^=arr[i];
            if(mp.find(xo^k)!=mp.end()){
                ans+=mp[xo^k];
            }
            mp[xo]++;
        }
        return ans;
    }
};