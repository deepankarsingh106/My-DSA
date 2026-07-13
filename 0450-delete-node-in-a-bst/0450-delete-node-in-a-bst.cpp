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
    int minimum(TreeNode* root){
        TreeNode* temp = root;
        while(temp->left){
            temp = temp->left;
        }
        return temp->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root -> val == key){
            // 0 child
            if(root->left == nullptr && root->right == nullptr){
                delete root;return nullptr;
            }

            // 1 child
            // left child only
            if(root -> left != nullptr && root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            //right child only

            if(root -> right != nullptr && root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // 2 child
            if(root->left && root->right){
                int mini = minimum(root->right);
                root->val = mini;
                root->right = deleteNode(root->right,mini);
                return root;
            }


        }
        else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else    root->left = deleteNode(root->left,key);
        return root;
    }
};