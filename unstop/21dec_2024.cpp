
#include <bits/stdc++.h>
#include <string>
using namespace std;

string isvalid(string s) {
    int n = s.size();
    int i = n - 2;
    
    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
    }
    if (i < 0) {
        return "";
    }
    int j = n - 1;
    while (s[j] <= s[i]) {
        j--;
    }
    
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
    
    return s;
}

string encodeMessage(string s, int t) {
    while (t--) {
        string ns= isvalid(s);
        if (ns== "") { 
            return "FAIL";
        }
        s = ns; 
    }
    return s;
}



int main() {
    int n, t;
    string s;
    cin >> n >> t;
    cin >> s;
    string result = encodeMessage(s, t);
    cout << result << "\n";
    return 0;
}
