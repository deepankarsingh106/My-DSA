class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int prefixcount = 0;
    TrieNode(char d){
        this->data = d;
        for(int i = 0;i<26;i++){
            children[i] = nullptr;
        }
        prefixcount = 0; 
    }
};
class Trie{
    public:
    
    TrieNode* root;
    
    Trie(char d){
        root = new TrieNode(d);
    }
    void insertWord(TrieNode* root,const string &w,int idx){
        if(w.size() == idx){
            return;
        }
        int i = w[idx]-'a';
        if(root->children[i]){
            root = root->children[i];
        }
        else{
            root->children[i] = new TrieNode(w[idx]);
            root = root -> children[i];
        }

        root->prefixcount++;
        
        insertWord(root,w,idx+1);
    }
    void insert(const string w){
        int idx = 0;
        insertWord(root,w,idx);
    }
    void PrefixCountUtil(TrieNode* root,const string &w,int &count,int i){
        if(w.size() == i){
            return;
        }

        int idx = w[i]-'a';


        if(root->children[idx]){
            count += root->children[idx]->prefixcount;
            root = root->children[idx];
        }
        else return;
        PrefixCountUtil(root,w,count,i+1);
    }
    int prefixSum(const string result){
        int count = 0,idx = 0;
        PrefixCountUtil(root,result,count,idx);
        return count;  
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;

        Trie* t = new Trie('\0');

        for(string i:words){
            t->insert(i);
        }
        for(string i:words){
            int result = t->prefixSum(i);
            ans.push_back(result);
        }

        return ans;
    }
};