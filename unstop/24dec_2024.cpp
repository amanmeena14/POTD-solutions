#include <bits/stdc++.h>
using namespace std;

int FirstWrongDecision(string s) {
    // User logic goes here
    auto it=lower_bound(s.begin(),s.end(),'W');
    if (it == s.end() || *it != 'W') {
        return -1;
    }
    return it-s.begin();
}

int main() {
    string str;
    cin >> str;
    // Call the function FirstWrongDecision().
    cout << FirstWrongDecision(str) << endl;
    return 0;
}