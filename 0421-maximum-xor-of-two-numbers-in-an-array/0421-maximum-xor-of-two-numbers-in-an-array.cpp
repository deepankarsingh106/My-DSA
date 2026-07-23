class TrieNode{
    public:
    TrieNode* children[2];
    TrieNode(){
        children[0] = children[1] = nullptr;
    }
};
class Trie{
    public:
    
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }

    void insertBits(int n){
        TrieNode* node = root;
        for(int i = 31;i>=0;i--){
            // getting the ith bits
            int bit = (n >> i)&1;

            if(node->children[bit]){
                node = node->children[bit];
            }
            else{
                node->children[bit] = new TrieNode();
                node = node->children[bit];
            }
        }
    }

    int maxor(int num){
        TrieNode* node = root;
        int maxi = 0;

        for(int i = 31;i>=0 ;i--){

            int bit = (num >> i) & 1;

            if(node->children[1-bit]){
                maxi |= (1 << i);
                node = node->children[1-bit];
            }
            else{
                node = node->children[bit];
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* t = new Trie;

        for(int i:nums){
            t->insertBits(i);
        }
        int result = 0;

        for(int i:nums){
            result = max(result,t->maxor(i));
        }

        return result;
    }
};