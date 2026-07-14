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
private:
    void GreterSum(TreeNode* root,int &sum){
        if(root == nullptr) return;
        if(root -> left == nullptr && root ->right == nullptr){
            sum += root->val;
            root -> val = sum;
            return;
        }
        GreterSum(root->right,sum);
        root->val = root -> val + sum;
        sum = root->val;
        GreterSum(root->left,sum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        GreterSum(root,sum);
        return root;
    }
};