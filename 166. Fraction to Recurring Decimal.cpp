/*
Hillol
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long int num1 = numerator;
        long int num2 = denominator;

        if(num1 == 0) return "0";
        string ans = "";

        bool sign =  (num1 < 0) ^ (num2 < 0);


        if(sign) ans = "-";

        num1 = abs(num1);
        num2 = abs(num2);

        cout<<num1<<" "<<num2<<endl;
        long initial = (num1/num2);

        long remind = num1 % num2;

        ans += to_string(initial);

        if(remind == 0) return ans;

        unordered_map<int, int> mp;


        string res = ".";
        bool index = 0;
        while(remind > 0){
            if(mp.find(remind) != mp.end()){
                break;
            }

            mp[remind] = res.size();
            remind*=10;
            int d = remind/num2;
            res+=to_string(d);

            remind = remind % num2;

        }

        if(remind) {
            res.insert(mp[remind], "(");
            res+=")";
        }
        return ans + res;

    }
};
