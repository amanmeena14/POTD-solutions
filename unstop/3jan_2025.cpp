#include <bits/stdc++.h>
using namespace std;

std::vector<int> user_logic(int n, std::vector<int>& arr, int q, std::vector<int>& qs) {
    vector<int> res;
    sort(arr.begin(),arr.end());
    for(int i=0;i<q;i++){
        auto pos=lower_bound(arr.begin(),arr.end(),qs[i]);
        if(pos==arr.end()){
            res.push_back(-1);
        }
        else{
        int it=pos-arr.begin();
        res.push_back(arr[it]);
        }
    }
    return res;
}

int main() {
    int t;
    std::cin >> t;
    std::vector<int> results;
    
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (int j = 0; j < n; ++j) {
            std::cin >> arr[j];
        }
        int q;
        std::cin >> q;
        std::vector<int> queries(q);
        for (int k = 0; k < q; ++k) {
            std::cin >> queries[k];
        }
        // Call user logic function
        std::vector<int> result = user_logic(n, arr, q, queries);
        results.insert(results.end(), result.begin(), result.end());
    }
    // Print all results for each query in each test case
    for (const int& res : results) {
        std::cout << res << std::endl;
    }
    return 0;
}