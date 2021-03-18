class Solution {
public:
    int ans = 0;
    int sign = 1;
    int myAtoi(string s) {
        int n = s.size();
        long int number = 0;
        int flag = 0;
        //while(s[i]==)
        int i=0;
        while(i<n && s[i] == ' '){
            i++;
        }

        if(i<n && (s[i]=='+' || s[i] == '-')){
            sign = (s[i]=='+'? 1 : -1);
            i++;
        }

        while(i<n){
            if(s[i]>='0' && s[i] <='9'){
                //cout<<"in"<<endl;
                number *=10;
                number += (sign * (s[i]-'0'));

                if(number > INT_MAX){
                    return INT_MAX;
                }
                if(number <INT_MIN){
                    return INT_MIN;
                }
            }
            else {
                return number;
            }
            i++;
        }
        return number;
    }
};
