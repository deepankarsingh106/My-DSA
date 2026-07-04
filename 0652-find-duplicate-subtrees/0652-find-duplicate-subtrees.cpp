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
    string  solve(TreeNode* root,map<string,int>&mp,vector<TreeNode*>&ans){
        if(root == nullptr){
            return "#";
        }

        string left = solve(root->left,mp,ans);
        string right = solve(root->right,mp,ans);
        string s = to_string(root->val) +',' + left + ',' + right;
        if(mp[s] == 1)  ans.push_back(root);
        mp[s]++;
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        map<string,int> mp;
        solve(root,mp,ans);
        return ans;
    }
};