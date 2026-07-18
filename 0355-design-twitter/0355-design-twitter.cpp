class Twitter {
private:
    // storing the userId tweets with their timestamps and tweetsID 
    unordered_map<int,vector<pair<int,int>>> userID;
    // storing the follower following their followe
    unordered_map<int ,unordered_set<int>> following;
    // timestamps -> to detect at what instant they posted their tweets
    int time;
public:
    Twitter() {
        time  = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userID[userId].push_back(make_pair(time++,tweetId));
    }
    // IMP
    vector<int> getNewsFeed(int userId) {
        
        // MIN-HEAP -> to get the most recent tweets f
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        // getting the user tweets
        for(auto& i: userID[userId]){
            pq.push(i);
            if(pq.size() > 10)  pq.pop();
        }

        // getting the followers tweets
        for(int i: following[userId]){
            for(auto& j:userID[i]){
                pq.push(j);
                if(pq.size() > 10)  pq.pop();
            } 
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */