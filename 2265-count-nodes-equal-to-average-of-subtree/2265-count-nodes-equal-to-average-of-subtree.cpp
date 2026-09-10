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
    int sumofnodes(TreeNode* root,int &cnt,int &c){
        if(root == nullptr){
            return 0;
        }
        int lc = 0,rc = 0;
        int left = sumofnodes(root->left,lc,c);
        int right = sumofnodes(root->right,rc,c);
        cnt = lc+rc+1;
        int sum = left + root->val + right;
        bool check = sum/cnt == root->val;
        if(check)   c++;
        return sum;
    }
public:

    int averageOfSubtree(TreeNode* root) {
        if(root == nullptr) return 0;
        int cnt = 0,c = 0;
        sumofnodes(root,cnt,c);
        return c;

    }
};