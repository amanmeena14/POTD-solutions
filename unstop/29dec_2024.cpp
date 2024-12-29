#include <bits/stdc++.h>
using namespace std;
int longest_consecutive_character(const std::string &s) {
    int maxi=0,len=1;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            len++;
        }
        else{
            maxi=max(maxi,len);
            len=1;
        }
    }
    maxi=max(maxi,len);
    return maxi;
}

int main() {
    std::string s;
    std::getline(std::cin, s); // Reading the single line passcode string

    // Call user logic function and print the output
    int result = longest_consecutive_character(s);
    std::cout << result << std::endl;
    return 0;
}