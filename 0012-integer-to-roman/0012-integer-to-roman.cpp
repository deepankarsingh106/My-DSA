class Solution {
public:
    string intToRoman(int num) {
        


        vector<string> T = {"M","MM","MMM"};
        vector<string> H = {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> TE = {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> o = {"I","II","III","IV","V","VI","VII","VIII","IX"};

 
        string ans = "";
        
        int d = num/1000;
        if(d != 0){
            ans += T[d-1];
        }

        num %= 1000;
        d = num/100;
        if(d != 0){
            ans += H[d-1];
        }

        num %= 100;
        d = num/10;
        if(d != 0){
            ans += TE[d-1];
        }

        num %= 10;
        if(num!=0){
            ans += o[num-1];
        }

        return ans;

    }
};