class node{
public:
    int data;
    int row;
    int col;
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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //creating min heap
        int k = nums.size();
        priority_queue<node*,vector<node*>,compare> pq;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i=0;i<k;i++){
            maxi = max(maxi,nums[i][0]);
            mini = min(mini,nums[i][0]);
            node* temp = new node(nums[i][0],i,0);
            pq.push(temp);
        }

        int start = mini,end = maxi;
        while(!pq.empty()){

            node* temp = pq.top();
            pq.pop();
            // current row and col
            int i = temp->row;
            int j = temp->col;
            //updating the mini
            mini = temp->data;

            if(maxi-mini < end-start){
                start = mini;
                end = maxi;
            }
            if(j+1 < nums[i].size()){
                maxi = max(maxi,nums[i][j+1]);
                node* next = new node(nums[i][j+1],i,j+1);
                pq.push(next);
            }
            // 
            else{
                break;
            }
            
        }
        return {start,end};
    }
};