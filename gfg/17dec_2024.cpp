// User function Template for C++

class Solution {
  public:

    bool check(vector<int>& stalls,int k,int distance){
        int cowsPlaced = 1; 
        int lastPosition = stalls[0]; 

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPosition >= distance) {
                cowsPlaced++;
                lastPosition = stalls[i]; 
            }
            if (cowsPlaced >= k) return true; 
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        // Write your code here
        int l=1,r=stalls.back()-stalls.front(),ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            int cnt=0;
            if(check(stalls,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
        
    }
};