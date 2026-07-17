class node{
    public:
    int data;
    int row,col;
    node(int d,int i,int j){
        this->data = d;
        this->row = i;
        this->col = j;
    }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int K) {
        int k = matrix.size();
        int c = 1;
        //MEAN HEAP
        priority_queue<node*,vector<node*>,compare> pq;

        for(int i = 0;i<k;i++){
            node* temp = new node(matrix[i][0],i,0);
            pq.push(temp);
        }   

        while(!pq.empty()){

            node *temp = pq.top();
            pq.pop();
            if(c == K){
                return temp->data;
            }
            c++;
            int i = temp->row;
            int j = temp->col;
            if(j+1 < matrix[i].size()){
                node* next = new node(matrix[i][j+1],i,j+1);
                pq.push(next);
            }
        }
        return -1;
    }
};