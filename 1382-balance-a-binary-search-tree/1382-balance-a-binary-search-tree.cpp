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
    void inorderTraversal(TreeNode* root,vector<TreeNode*>&Node){
        if(root == NULL)    return;
        inorderTraversal(root->left,Node);
        Node.push_back(root);
        inorderTraversal(root->right,Node);
    }
    TreeNode* build(vector<TreeNode*>&in,int s,int e){
        if(s > e)   return nullptr;

        int mid = s + (e-s)/2;

        TreeNode* root = in[mid];

        root -> left = build(in,s,mid-1);
        root -> right = build(in,mid+1,e);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> in;
        inorderTraversal(root,in);
        return build(in,0,in.size()-1);        
    }
};