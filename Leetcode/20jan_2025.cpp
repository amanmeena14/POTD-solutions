class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,int> row,col,rr,cc;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[mat[i][j]]=i;
                col[mat[i][j]]=j;
            }
        }
        for(int i=0;i<arr.size();i++){
            rr[row[arr[i]]]++;
            cc[col[arr[i]]]++;
            if(rr[row[arr[i]]]==m || cc[col[arr[i]]]==n){
                return i;
            }
        }
        return -1;
    }
};