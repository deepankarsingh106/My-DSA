class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)  return false;
        //storing the freqency 
        map<int,int> freq;

        for(int i:hand){
            freq[i]++;
        }

        auto it = freq.begin(); // pointer it is 
        while(it != freq.end()){

            if(it->second == 0){
                ++it;
                continue;
            }

            auto start = it->first;
            // minimum count of the element i needed 
            // whenever next ot its element is there and 
            // otherwise diffrence led to > 1
            auto count = it->second;

            for(int i = 0;i<groupSize;i++){

                if(freq[i+start] < count)  return false;

                freq[i+start] -= count;
            }
            it++;
        }
    return true;}
};