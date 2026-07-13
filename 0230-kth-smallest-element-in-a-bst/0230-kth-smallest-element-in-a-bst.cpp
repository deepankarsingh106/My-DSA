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
    int getNode(TreeNode* root,int &i,int k){
        if(root == nullptr) return -1;
        // INORDER TRAVERSAL

        int left = getNode(root->left,i,k);
        if(left != -1){
            return left;
        }
        i++;
        if(i == k){
            return root->val;
        }
        return getNode(root->right,i,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return getNode(root,i,k);
    }
};