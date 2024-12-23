/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void func(unordered_map<int,vector<int>>& mp,TreeNode* root,int lev){
        if(root==nullptr)return;
        mp[lev].push_back(root->val);
        func(mp,root->left,lev+1);
        func(mp,root->right,lev+1);
    }
    // void func2(unordered_map<int,vector<int>>&mp,TreeNode* root,int lev,vector<int>&vv){
    //     if(root==nullptr)return;
    //     root->val=mp[lev][vv[lev]++];
    //     func2(mp,root->left,lev+1,vv);
    //     func2(mp,root->right,lev+1,vv);
    // }
    int minimumOperations(TreeNode* root) {
        unordered_map<int,vector<int>> mp;
        int ans=0;
        func(mp,root,0);
        for(auto it:mp){
            vector<int> temp=it.second;
            map<int,int> mmp;
            for(int i=0;i<temp.size();i++){
                mmp[temp[i]]=i;
            }
            int cnt=0;
            sort(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++){
                if(it.second[i]!=temp[i]){
                    cnt++;
                    int curr=mmp[temp[i]];
                    mmp[it.second[i]]=curr;
                    swap(it.second[curr],it.second[i]);
                }
            }
            ans+=cnt;

        }
        // int ind=mp.size();
        // vector<int> vv(ind+1);
        // func2(mp,root,0,vv);
        return ans;
    }
};