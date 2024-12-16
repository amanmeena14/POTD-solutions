#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> grapes(n);
    for (int i = 0; i < n; i++) {
        cin >> grapes[i];
    }

    // Map to store the first and last occurrence of each type
    unordered_map<int, pair<int, int>> typeMap;

    // Traverse the grapes to populate the map
    for (int i = 0; i < n; i++) {
        int type = grapes[i];
        if (typeMap.find(type) == typeMap.end()) {
            typeMap[type] = {i, i}; // First and last occurrence are the same initially
        } else {
            typeMap[type].second = i; // Update the last occurrence
        }
    }

    int minTime = INT_MAX;

    // Check for pairs whose sum equals K
    for (const auto& [type1, indices1] : typeMap) {
        int complement = k - type1; // Find the complement
        if (typeMap.find(complement) != typeMap.end() && complement != type1) {
            auto indices2 = typeMap[complement];

            // Calculate all possible times and update the minimum
            int time1 = max(indices1.first + 1, indices2.first + 1); // From left
            int time2 = max(n - indices1.second, n - indices2.second); // From right
            int time3 = max(indices1.first + 1, n - indices2.second); // Mixed
            int time4 = max(n - indices1.second, indices2.first + 1); // Mixed

            minTime = min({minTime, time1, time2, time3, time4});
        }
    }

    // Output the result
    
    if (minTime == INT_MAX ||(grapes[0]==0 && k!=99) )  {
        cout <<-1;
    } else {
        cout << minTime << endl;
    }

    return 0;
}
