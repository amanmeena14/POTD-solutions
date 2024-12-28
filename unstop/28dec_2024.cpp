#include <bits/stdc++.h>
using namespace std;

bool func(vector<vector<int>>& dp,vector<int>& arr,int i,int sum,int k){
    if(sum==k){
        return true;
    }
    if(sum>k || i>=arr.size()){
        return false;
    }
    if (dp[i][sum] != -1) { 
        return dp[i][sum];
    }
    bool take=func(dp,arr,i+1,sum+arr[i],k);
    bool nottake=func(dp,arr,i+1,sum,k);
     dp[i][sum] = take || nottake;
    return dp[i][sum];
}
void can_select_people(int N, int K, std::vector<int>& arr) {
    // Write your logic here.
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));
    if(func(dp,arr,0,0,K)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }
    can_select_people(N, K, arr);
    return 0;
}