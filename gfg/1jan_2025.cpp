class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>> vs;
        int n=arr.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            vector<string> v;
            vector<int> vv(26,0);
            if(vis[i]==0){
                v.push_back(arr[i]);
                vis[i]=1;
                for(int j=0;j<arr[i].size();j++){
                    vv[arr[i][j]-'a']++;
                }
                for(int j=i+1;j<n;j++){
                    vector<int> vvv(26,0);
                    int flag=1;
                    for(int k=0;k<arr[j].size();k++){
                        vvv[arr[j][k]-'a']++;
                    }
                    for(int k=0;k<26;k++){
                        if(vv[k]!=vvv[k]){
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1){
                        vis[j]=1;
                        v.push_back(arr[j]);
                    }
                }
                vs.push_back(v);
            }
        }
        return vs;
    }
};