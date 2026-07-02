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
    void solve(TreeNode* &root,int val,int d){
        if(root == nullptr) return;
        if(d == 2){
            TreeNode* templeft = root->left;
            TreeNode* tempright = root->right;
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);
            root->left = l;root->right = r;
            l->left = templeft;
            r->right = tempright;
            return;
        }
        solve(root->left,val,d-1);
        solve(root->right,val,d-1);

    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *root1 = new TreeNode(val);
            root1->left = root;
            return root1; 
        }
        solve(root,val,depth);
        return root;
    }
};