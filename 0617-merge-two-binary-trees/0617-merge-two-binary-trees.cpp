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
    void solve(TreeNode* &root1,TreeNode*root2){
        if(root1 == nullptr && root2 == nullptr)    return;
        if(root1 != nullptr && root2 == nullptr)    return;
        if(root1 == nullptr &&  root2 != nullptr){
            root1 = root2;
            root1->val = root2->val;
            return;
        }
        if(root2 != nullptr && root1 != nullptr){
            root1 -> val = root1 ->val + root2 ->val;
        }
        solve(root1->left,root2->left);
        solve(root1->right,root2->right);
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        solve(root1,root2);
        return root1;
    }
};