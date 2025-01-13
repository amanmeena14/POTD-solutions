class Solution {

  public:
    int maxWater(vector<int> &arr) {
         int n = arr.size();
        if (n < 2) return 0;

        int left = 0, right = n - 1;
        int maxArea = 0;

        while (left < right) {
            int height = min(arr[left], arr[right]);
            int width = right - left;
            maxArea = max(maxArea, height * width);

            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};