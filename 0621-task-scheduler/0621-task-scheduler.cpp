class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;
        // count of the frequency of each task
        for(char ch:tasks){
            mp[ch]++;
        }

        priority_queue<int>pq;
        for(auto &i:mp){
            pq.push(i.second);
        }

        int time = 0;

        while(!pq.empty()){
            // storing of the tasks left
            
            vector<int> temp;
            int cycle = n+1;
            int i=0;
            while(i < cycle && !pq.empty()){

                int task = pq.top();pq.pop();
                task--;
                time++;i++;
                if(task > 0)    temp.push_back(task);
            }

            for(int i:temp){
                pq.push(i);
            }

            if(pq.empty())  break;

            time += (cycle-i);
        }

    return time;
    }
};