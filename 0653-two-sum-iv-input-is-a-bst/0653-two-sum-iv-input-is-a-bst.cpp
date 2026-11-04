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
    void inorderTraversal(TreeNode *root,vector<TreeNode*>&in){
    if(root == NULL)    return;
    inorderTraversal(root->left,in);
    in.push_back(root);
    inorderTraversal(root->right,in);
}
public:
    bool findTarget(TreeNode* root, int k) {
        vector<TreeNode*> in;
        inorderTraversal(root,in);
        int n = in.size();
        int i = 0,j=in.size()-1;
        while(i < j){
            int sum = in[i]->val+in[j]->val;
            if(sum == k){
                return true;
            } 
            else if(sum > k){
                j--;
            }
            else i++;
        }
        return false;
    }
};