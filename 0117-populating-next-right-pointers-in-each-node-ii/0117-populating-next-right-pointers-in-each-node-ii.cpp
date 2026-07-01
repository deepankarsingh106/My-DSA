/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void solve(Node* root){
        if(root == nullptr) return;
        Node* temp = root;
        Node* hd = nullptr;
        Node* tl = nullptr;
        while(temp){
            if(temp->left){
                if(hd == nullptr && tl == nullptr){
                    hd = temp->left;
                    tl = temp->left;
                }
                else{
                    tl->next = temp->left;
                    tl=temp->left;
                }
            }
            if(temp->right){
                if(hd == nullptr && tl == nullptr){
                    hd = temp->right;
                    tl = temp->right;
                }
                else{
                    tl->next = temp->right;;
                    tl = temp->right;;
                }
            }
            temp=temp->next;
        }
        
        solve(hd);
    }
public:
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};