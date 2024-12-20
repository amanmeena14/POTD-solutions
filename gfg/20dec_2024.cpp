class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int m=mat.size(),n=mat[0].size();
        int left=0,right=n-1,top=0,bottom=m-1;
        vector<int> res;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                res.push_back(mat[top][i]);
            }
            top++;
            for(int j=top;j<=bottom;j++){
                res.push_back(mat[j][right]);
            }
            right--;
            if(top<=bottom){
            for(int i=right;i>=left;i--){
                res.push_back(mat[bottom][i]);
            }
                bottom--;
            }
            if(left<=right){
            for(int j=bottom;j>=top;j--){
                res.push_back(mat[j][left]);
            }
            left++;
                
            }
        }
        return res;
    }
};