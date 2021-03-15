class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }

        long long int d = abs(dividend);
        long long int s = abs(divisor);
        //cout<<d<<" "<<s<<endl;
        int sign = (dividend >=0 ^ divisor>=0 ? -1 : 1);
        long int ans = 0;

        while(d >= s){
            long int cnt = 0;
            long int tempD = 0;

            while(tempD <= d){
                if(cnt==0){
                    cnt=1;
                    tempD=s;
                }
                else{
                    cnt= cnt<<1;
                    tempD=tempD<<1;
                }
            }
            if(cnt>0){
                tempD = tempD>>1;
                cnt = cnt>>1;
                ans+=cnt;
                d= d-tempD;
            }
        }
        return ans*sign;
    }
};
