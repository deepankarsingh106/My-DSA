class TrieNode{
    public:
        TrieNode* children[2];

        TrieNode(){
            for(int i = 0;i<2;i++){
                children[i] = nullptr;
            }
        }
};

class Trie{
    public:
        Trie(){
            root = new TrieNode();
        }

        TrieNode * root;

        void insertBitsUtil(int n){
            TrieNode* node = root;
            for(int i = 31;i>=0;i--){
                //get the i-th bit
                int bit = (n >> i) & 1;
                if(node->children[bit] == nullptr){
                    node->children[bit] = new TrieNode();
                    node = node-> children[bit]; 
                }
                else{
                    node = node->children[bit];}
            }
        }

        int maxxor(int n){
            int result = 0;

            TrieNode* node = root;

            for(int i = 31;i>=0;i--){

                int bit = (n >> i)&1;

                if(node->children[1-bit]){
                    result |= (1 << i);
                    node = node->children[1-bit];
                }
                else{
                    node = node->children[bit];
                }
            }

            return result;
        }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int>ans(queries.size(),0);

        Trie *t = new Trie();

        int n = nums.size();

        sort(nums.begin(),nums.end());

        // storing the queries on the basis of the ending idx
        vector<pair<int,pair<int,int>>> anotherqueries;
        
        int idx = 0;
        
        for(auto &i: queries){
            anotherqueries.push_back(make_pair(i[1],make_pair(i[0],idx)));
            idx++;
        }

        sort(anotherqueries.begin(),anotherqueries.end());

        //int n = nums.size();
        int index = 0;
        for(auto &i:anotherqueries){

            while(index < n && nums[index] <= i.first){
                t->insertBitsUtil(nums[index]);index++;
            }

            if(index == 0){
                ans[i.second.second] = -1;
            }
            else{
                ans[i.second.second] = t->maxxor(i.second.first);
            }
        }

        return ans;
    }
};