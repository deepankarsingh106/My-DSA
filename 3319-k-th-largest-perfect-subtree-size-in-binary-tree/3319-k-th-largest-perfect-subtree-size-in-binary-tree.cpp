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
    tuple<bool,int,int> solve(TreeNode* root,vector<int>&ans){
        if(root == nullptr){
            return {true, 0, 0};
        }

        tuple<bool,int,int> left = solve(root->left,ans);
        tuple<bool,int,int> right = solve(root->right,ans);
        tuple<bool,int,int> result;
        // get<0>(left)   // bool
        // get<1>(left)   // height
        // get<2>(left)   // size
        if(get<1>(left) == get<1>(right) && get<0>(left) && get<0>(right) && get<2>(left) == get<2>(right)){
            get<0>(result) = true;
            get<1>(result) = get<1>(left)+1;
            ans.push_back(get<2>(left)+get<2>(right)+1);

        }else{
            get<0>(result) = false;
            get<1>(result) = max(get<1>(left),get<1>(right))+1;
        }
        get<2>(result) = get<2>(left)+get<2>(right)+1;
        return result;
    }
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        if(root == nullptr) return -1;
        vector<int> ans;
        tuple<bool,int,int> check = solve(root,ans);
        if(ans.size() < k ) return -1;
        sort(ans.begin(),ans.end(),greater<int>());
        return ans[k-1];
    }
};