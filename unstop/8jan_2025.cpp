#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD = 1000000007;
int32_t main(){
    int N;
    cin>>N;
      if (N % 2 != 0) {
        cout<<0<<endl;
        return 0;
    }
    vector<int> dp(N + 1, 0);
    dp[0] = 0;
    dp[2] = 3;
    int res=4;
    for (int i = 4; i <= N; i += 2) {
        dp[i] = (dp[i - 2] + 2*res)%MOD;
        res = (res+dp[i]);
    }
    cout<<dp[N]<<endl;
    return 0;
}