#include <bits/stdc++.h>
using namespace std;

// User-defined function declaration
int formLargestNumber(int n, vector<int> arr);

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Call the user-defined function
    int result = formLargestNumber(n, arr);
    
    // Print the result
    cout << result << endl;
    
    return 0;
}

// User-defined function definition
int formLargestNumber(int n, vector<int> arr) {
    // User needs to implement the logic here
    int fir=INT_MAX,sec=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<fir){
            sec=fir;
            fir=arr[i];
        }
        else if(arr[i]<sec){
            sec=arr[i];
        }
    }
    int ans=max(fir,sec);
    ans*=10;
    ans+=min(fir,sec);
    return ans;
}
