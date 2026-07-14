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
    struct info{
        bool isBST;
        int sum,maxi,mini;
    };
    info solve(TreeNode* root,int &ans){
        if(root == nullptr){
            return {true,0,INT_MIN,INT_MAX};
        }
        info left = solve(root->left,ans);
        info right = solve(root->right,ans);

        if(left.isBST && right.isBST && left.maxi < root->val && right.mini > root->val){
            int curr = left.sum + right.sum + root->val;
            ans = max(ans,curr);

            return {true,curr,max(root->val,right.maxi),min(root->val,left.mini)};
            //return {true,curr,max(root->val,left.maxi),min(root->val,right.mini)};
            // maximum part from the right side of the left tree
            // minimum part from the left side of the right tree

        }
        return {false,0,0,0};
    }
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};