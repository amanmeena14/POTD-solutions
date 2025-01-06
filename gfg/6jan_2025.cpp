class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); // Sort the array
        int n = arr.size();
        int curr=-1;
        int res = INT_MAX; // To track the closest sum
        vector<int> pair(2, 0);

            int left = 0, right = n - 1;

            while (left < right) {

                int sum = arr[left] + arr[right];
                if (abs(target - sum) < abs(target - res) || (abs(target-sum)==abs(target-res) && (arr[right]-arr[left]>curr))) {
                    res = sum;
                    curr=arr[right]-arr[left];
                    pair[0] = min(arr[left], arr[right]);
                    pair[1] = max(arr[left], arr[right]);
                }

                // Adjust pointers
                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        
        if(arr.size()==1){
            return {};
        }
        return pair;
    }
};
