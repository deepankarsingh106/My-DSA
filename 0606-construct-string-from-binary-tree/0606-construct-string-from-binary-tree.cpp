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
    void solve(TreeNode* root,string &ans){
        if(root == nullptr) return;
        ans += to_string(root->val);
        if(root -> left == nullptr && root->right == nullptr){
            return;
        }
        ans += '(';
        if(root -> left){
            solve(root->left,ans);
        }
        ans += ')';
        if(root -> right){
            //if(root -> left == nullptr) ans+='()';
            ans += '(';
            solve(root->right,ans);
            ans += ')';
        }
    }
public:
    string tree2str(TreeNode* root) {
        string ans = "";
        if(root == nullptr) return ans;


        solve(root,ans);
        return ans;
    }
};