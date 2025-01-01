#include<bits/stdc++.h>
using namespace std;

int countLuckyPairs(int p, int n, int m, vector<int> v);

int main() {
    int p, n, m;
    cin >> p >> n >> m;
    vector<int> v(p);
    for (int i = 0; i < p; i++) {
        cin >> v[i];
    }
    int ans = countLuckyPairs(p, n, m, v);
    cout << ans << endl;
    return 0;
}

int countLuckyPairs(int p, int n, int m, vector<int> v) {
    // User's logic goes here
    int cnt=0,ans=0;
    for(int i=0;i<v.size();i++){
        if(v[i]%n==0 || v[i]%m==0){
            ans+=cnt;
            cnt++;
        }
    }
    return ans;
}