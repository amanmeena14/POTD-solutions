class Solution {
public:
    std::vector<std::vector<int>> findTriplets(std::vector<int> &arr) {
        std::map<int, std::vector<int>> mp;
        std::vector<std::vector<int>> v;

        // Map the first element with index 0
        mp[arr[0]].push_back(0);

        // Iterate through the array
        for (int i = 1; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int target = -(arr[i] + arr[j]);
                
                // Check if the target exists in the map
                if (mp.find(target) != mp.end()) {
                    // Iterate over all indices that map[target] holds
                    for (int k : mp[target]) {
                        // Only consider triplets where k < i < j to maintain order
                        if (k < i) {
                            v.push_back({k, i, j});
                        }
                    }
                }
            }
            // Map the current element's index
            mp[arr[i]].push_back(i);
        }

        return v;
    }
};