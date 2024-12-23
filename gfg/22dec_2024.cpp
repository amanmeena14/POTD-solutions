class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
         for(int i = 0 ; i < mat.size() ;i++)  {  
      if(binary_search(mat[i].begin(), mat[i].end(), x)){
          return 1;
      }
    }
    return 0;
    }
};