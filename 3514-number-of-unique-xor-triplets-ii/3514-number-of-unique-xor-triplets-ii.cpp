class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }

        vector<int> temp;

        for(int i:st){
            temp.push_back(i);
        }

        st.clear();
        for(int i = 0;i<temp.size();i++){
            for(int j = i;j<temp.size();j++){

                int x = temp[i] ^ temp[j];
                st.insert(x);
                
            }
        }
        unordered_set<int> st1;
        for(int i:st){
            for(int j = 0;j<temp.size();j++){
                int x = i^temp[j];
                st1.insert(x);
            }
        }

        return st1.size();
    }
};