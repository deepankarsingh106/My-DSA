class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(string s:operations){
            if(s == "C"){
                st.pop();
            }
            else if(s == "D"){
                int d = st.top();
                d *= 2;
                st.push(d);
            }
            else if(s == "+"){  
                int d1 = st.top();st.pop();
                int d2 = st.top();
                int sum = d1+d2;
                st.push(d1);
                st.push(sum);
            }
            else{
                int d = stoi(s);
                st.push(d);
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();st.pop();
        }   
        return sum;
    }
};