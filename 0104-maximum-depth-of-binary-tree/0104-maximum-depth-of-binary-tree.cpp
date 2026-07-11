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
    int levelordertraversal(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = levelordertraversal(root->left);
        int right = levelordertraversal(root->right);
        return max(left,right)+1;
    }
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        return levelordertraversal(root);
        
    }
};