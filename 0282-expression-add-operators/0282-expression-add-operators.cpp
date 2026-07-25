class Solution {

    void solve(string &num,int target,int start,long long curr_val,long long last_opherand,string expression,vector<string>&results){
        
        //BASE CASE
        if(start == num.size()){
            if(curr_val == target){
                results.push_back(expression);
            }
            return;
        }

        for(int i = start;i<num.size();i++){
            

            //case of the leading zero like  -> 05
            if(i > start && num[start] == '0') return;

            string cur_num = num.substr(start,i-start+1);
            
            // to num from the string
            long long cur_num_val = stoll(cur_num);

            if(start == 0){
                solve(num,target,i+1,cur_num_val,cur_num_val,cur_num,results);
            }
            else{
                //addition of the numbers
                solve(num,target,i+1,curr_val+cur_num_val,cur_num_val,expression + '+' + cur_num,results);

                //subtraction of the number
                solve(num,target,i+1,curr_val-cur_num_val,-cur_num_val,expression+'-'+cur_num,results);

                // multiplication of the number

                solve(num,target,i+1,curr_val - last_opherand + (last_opherand*cur_num_val),last_opherand * cur_num_val,expression + '*' + cur_num,results);

            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> results;

        solve(num,target,0,0,0,"",results);

        return results;
    }
};