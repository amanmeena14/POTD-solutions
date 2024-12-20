class Solution {
public:
    void func(unordered_map<int, vector<int>>& mp, TreeNode* root, int lev) {
        if (root == nullptr) return;

        if (lev % 2 != 0) {
            mp[lev].push_back(root->val);
        }
        func(mp, root->left, lev + 1);
        func(mp, root->right, lev + 1);
    }

    void func2(unordered_map<int, vector<int>>& mp, TreeNode* root, int lev, vector<int>& ind) {
        if (root == nullptr) return;

        if(lev%2!=0){
            root->val=mp[lev][ind[lev]++];
        }
        func2(mp, root->left, lev + 1,ind);
        func2(mp, root->right, lev + 1,ind);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        unordered_map<int, vector<int>> mp;
        func(mp, root, 0);
         for (auto& [level, values] : mp) {
            reverse(values.begin(), values.end());
        }
        
        vector<int> ind(15,0);
        func2(mp, root, 0,ind);
        return root;
    }
};
