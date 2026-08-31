/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
            return {-1,-1};
        }
        vector<int> ans;
        int p = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nextnode = head->next->next;
        while(nextnode != nullptr){
            if(((prev->val < curr->val) && (curr->val > nextnode->val)) || ((prev->val > curr->val) && (curr->val < nextnode->val))){
                ans.push_back(p);
            }
                prev = curr;
                curr = nextnode;
                nextnode = nextnode->next;
                p++;
        }
        int n = ans.size();
        if(n <= 1)  return {-1,-1};
        int mini = INT_MAX,maxi = INT_MIN;
        sort(ans.begin(),ans.end());
        for(int i = 0;i+1<n;i++){
            //for(int j = i+1;j<n;j++){
            mini = min(mini,ans[i+1]-ans[i]);
            //maxi = max(maxi,ans[j]-ans[i]);    
        }
        maxi = max(maxi,ans[n-1]-ans[0]);
        if(mini == INT_MAX && maxi == INT_MIN){
            return {-1,-1};
        }
    return {mini,maxi};}
};