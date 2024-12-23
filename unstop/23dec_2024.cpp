#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumMutatedViruses(int V, vector<int>& levels) {
    // Step 1: Sort the contamination levels
    sort(levels.begin(), levels.end());
    
    vector<bool> used(V, false); // Track used viruses
    int mutatedViruses = 0;

    // Step 2: Iterate through the array using the "three-sum" approach
    for (int i = 0; i < V; i++) {
        if (used[i]) continue; // Skip if the virus is already used
        
        int left = i + 1, right = i + 2; // Initialize two pointers

        while (right < V) {
            // Check if we can form a valid triplet
            if (!used[left] && !used[right]) {
                // Check for identical triplet
                if (levels[i] == levels[left] && levels[left] == levels[right]) {
                    mutatedViruses++;
                    used[i] = used[left] = used[right] = true;
                    break; // Move to the next triplet
                }
                // Check for consecutive triplet
                if (levels[i] + 1 == levels[left] && levels[left] + 1 == levels[right]) {
                    mutatedViruses++;
                    used[i] = used[left] = used[right] = true;
                    break; // Move to the next triplet
                }
            }
            // Adjust the right pointer
            right++;
            if (right >= V) {
                left++;
                right = left + 1;
            }
        }
    }

    return mutatedViruses;
}

int main() {
    int V;
    cin >> V;
    vector<int> levels(V);
    for (int i = 0; i < V; i++) {
        cin >> levels[i];
    }
    cout << maximumMutatedViruses(V, levels) << endl;
    return 0;
}
