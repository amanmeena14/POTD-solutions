#include <bits/stdc++.h>
using namespace std;

// Function to be implemented by the user
vector<int> number_of_options(int n, vector<int>& prices, int m, vector<int> coins_per_day) {
    // User will write the logic here
    vector<int> res;
    sort(prices.begin(),prices.end());
    for(auto cc: coins_per_day){
        int ans=upper_bound(prices.begin(),prices.end(),cc)-prices.begin();
        res.push_back(ans);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int m;
    cin >> m;
    vector<int> coins_per_day(m);
    for (int i = 0; i < m; i++) {
        cin >> coins_per_day[i];
    }

    // Call the function with the appropriate arguments
    vector<int> result = number_of_options(n, prices, m, coins_per_day);

    // Print the results as per the output format
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}