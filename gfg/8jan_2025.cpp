class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int lb=lower_bound(arr.begin()+j+1,arr.end(),arr[i]+arr[j])-arr.begin();
                ans+=(lb-1-j);
            }
        }
        return ans;
    }
};