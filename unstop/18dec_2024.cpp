#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll factorial(int n) {
    if (n == 0 || n == 1) return 1LL;
    return n *1LL* factorial(n - 1);
}

ll calculateDistinctPermutations(string s) {
    unordered_map<char, int> freq;
    char cc;
    for (char c : s) freq[c]++;
    ll fact = factorial(s.length());
    int maxi=INT_MIN;
    for (auto p : freq) {
        fact /= factorial(p.second);
        if(maxi<p.second){
        maxi=max(maxi,p.second);
        cc=p.first;}
        }

        ll nfact=factorial(s.length()-maxi+1);
    for(auto p: freq){
        if(p.first==cc){
            continue;
        }
        nfact/=factorial(p.second);
    }

    return fact-nfact;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll result = calculateDistinctPermutations(s);
        cout << result << endl;
    }
    return 0;
}
