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
    int minimumoperation(vector<int>&original){
        int n = original.size();
        int ans = 0;
        vector<int>target = original;
        sort(target.begin(),target.end());
        unordered_map<int,int>mp;

        for(int i = 0;i<n;i++){
            mp[original[i]] = i;
        }

        for(int i = 0;i<n;i++){
            if(original[i] != target[i]){
                ans++;

                int idx = mp[target[i]];
                mp[original[i]] = idx;
                swap(original[idx],original[i]);
            }
        }
        return ans;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        int ans = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size,0);
            for(int i = 0;i<size;i++){
                TreeNode* temp = q.front();q.pop();
                level[i] = temp->val;
                if(temp -> left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans += minimumoperation(level);
        }
        return ans;
    }
};