class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        for(int i = 0 ; i < mat.size() ;i++)  {  
      if(binary_search(mat[i].begin(), mat[i].end(), x)){
          return 1;
      }
    }
    return 0;
    }
};