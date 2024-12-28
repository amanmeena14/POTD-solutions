class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n + 1, 0); 
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }

        vector<vector<int>> dp(n+1,vector<int>(4,0));
        vector<vector<int>> trace(n+1,vector<int>(4,-1));
        for(int j=1;j<=3;j++){
            for(int i=j*k;i<=n;i++){
                int curr=pref[i]-pref[i-k];
                if(dp[i-k][j-1]+curr>dp[i-1][j]){
                    dp[i][j]=dp[i-k][j-1]+curr;
                    trace[i][j]=i-k;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                    trace[i][j]=trace[i-1][j];
                }
            }
        }
        vector<int> res(3,0);
        int ind=n;
        for(int j=3;j>=1;j--){
            res[j-1]=trace[ind][j];
            ind=res[j-1];
        }
        return res;
    }
};
