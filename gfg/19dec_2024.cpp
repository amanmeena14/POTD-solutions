class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n=arr.size(),j=n;
        int l=0,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if((arr[mid]-1-mid)>=k){
                j=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return j+k;
    }
};