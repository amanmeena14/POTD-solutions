#include <bits/stdc++.h>
using namespace std;

// Function prototype
int maxDigitReversalSum(int A, int B);

int main() {
    int A, B;
    cin >> A >> B;

    int result = maxDigitReversalSum(A, B);
    cout << result << endl;

    return 0;
}

// User will write the logic inside this function
int maxDigitReversalSum(int A, int B) {
    // User's code goes here
    int sum=0;
    for(int i=A;i<=B;i++){
        int temp=i;
        string st=to_string(i);
        reverse(st.begin(),st.end());
        int num=0;
        for(int j=0;j<st.size();j++){
            num=num*10+(st[j]-'0');
        }
        sum+=max(num,temp);
    }
    return sum;
    return 0;
}