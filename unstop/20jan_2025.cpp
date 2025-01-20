#include <bits/stdc++.h>
using namespace std;

bool can_form_by_interleaving(const std::string& s, const std::string& t) {
    int i=0,j=0;
    while(i<s.size() && j<t.size()){
        if(s[i]==t[j]){
            i++;
        }
        j++;
    }
    j=0;
    while(i<s.size() && j<t.size()){
        if(s[i]==t[j]){
            i++;
        }
        j++;
    }
    if(i==s.size()){
        return true;
    }
    return false;
}

int main() {
    std::string S, T;
    std::cin >> S >> T;
    bool result = can_form_by_interleaving(S, T);
    std::cout << (result ? 1 : 0) << std::endl;
    return 0;
}