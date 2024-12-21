class Solution {
public:
    int func(int i,int p,vector<vector<int>>& tree,vector<int>& values,int k,int&comp){
        int sum=0;
        for(int child:tree[i]){
            if(child!=p){
                sum+=func(child,i,tree,values,k,comp);
                sum%=k;
            }
        }
        sum+=values[i];
        sum%=k;
        if(sum==0)comp++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> tree(n);
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        int comp=0;
        func(0,-1,tree,values,k,comp);
        return comp;
    }
};