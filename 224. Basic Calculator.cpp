class Solution {
public:
    int calculate(string s) {
        stack<pair<int,int>> st;

        int len = s.size();

        int number= 0;
        int sign = 1;
        int sum=0;
        for(int i=0;i<len;i++){

            if('0'<=s[i] && s[i]<='9'){
                number *= 10;
                number += (s[i] - '0');
            }
            else{
                //cout<<s[i]<<" #"<<endl;
                if(s[i]==' ')
                    continue;
                //cout<<number<<" "<<sign<<endl;
                sum+=number*sign;

                number =0;

                if(s[i]=='-') sign =-1;
                if(s[i]=='+') sign = 1;


                if(s[i]=='('){
                    st.push(make_pair(sum, sign));
                    sum = 0;
                    sign=1;
                }

                if(s[i]==')' && !st.empty()){
                   sum = st.top().first + st.top().second*sum;
                   st.pop();
                }
            }
        }

        sum+=number*sign;

        return sum;
    }
};
