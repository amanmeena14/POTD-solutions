class Solution {
public:
    vector<int> fdeg(vector<vector<int>>&tree,int n,int&diam){
        if(n <= 1) {
        return {0}; 
        }
        queue<int> q;
        vector<int> deg(n);

        for(int i=0;i<n;i++){
            deg[i]=tree[i].size();
            if(deg[i]==1){
                q.push(i);
            }
        }
        int tnodes=deg.size();
        while(tnodes>2 ){
            int lef=q.size();
            tnodes-=lef;
            diam++;
            for(int i=0;i<lef;i++){
                int top=q.front();
                q.pop();
                for(int it:tree[top]){
                    deg[it]--;
                    if(deg[it]==1){
                        q.push(it);
                    }
                }
            }
        }
        if(tnodes==2)diam=2*diam+1;
        else diam=2*diam;
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
    int dfs(vector<vector<int>>&tree,int cen,int par){
        int len=0;
        for(int it:tree[cen]){
            if(it!=par){
                int nlen=dfs(tree,it,cen);
                len=max(len,nlen+1);
            }
        }
        return len;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> tree1(edges1.size()+1),tree2(edges2.size()+1);
        int n=edges1.size()+1,m=edges2.size()+1;
        for(auto it:edges1){
            int a=it[0],b=it[1];
            tree1[a].push_back(b);
            tree1[b].push_back(a);
        }
        for(auto it:edges2){
            int a=it[0],b=it[1];
            tree2[a].push_back(b);
            tree2[b].push_back(a);
        }
        int diam1=0,diam2=0;
        vector<int> centa=fdeg(tree1,n,diam1);
        vector<int> centb=fdeg(tree2,m,diam2);
        int ca=centa[0],cb=centb[0];
        int lena=dfs(tree1,ca,-1);
        int lenb=dfs(tree2,cb,-1);
        cout<<ca<<cb;
        return max({diam1,diam2,1+lena+lenb});
    }
};