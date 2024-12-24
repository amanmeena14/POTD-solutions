class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int l=mat.size(),r=mat[0].size();
        int ll=0,hh=l*r-1;
        while(ll<=hh){
            int mid=(ll+hh)/2;
            if(mat[mid/r][mid%r]==x){
                return true;
            }
            if(mat[mid/r][mid%r]<x){
                ll=mid+1;
            }
            else{
                hh=mid-1;
            }
        }
        return false;
    }
};