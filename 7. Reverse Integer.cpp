class Solution {
public:
    int reverse(int x) {
        int sign= x<0? -1:1;
        int n = 0;

        int mn = INT_MIN/10;
        int mnd= INT_MIN%10;
        int mx = INT_MAX/10;
        int mxd = INT_MAX%10;

        //cout<<mn<<" "<<INT_MIN <<" "<<mnd<<endl;
        while(x){
            int d = x%10;
            if(n<mn || (n==mn && d<mnd) ) return 0;
            if(n>mx || (n==mx && d>mxd)) return 0;
            n=n*10;
            n+=d;
            x/=10;
            if(n>0 && sign==-1) n*=-1;

        }
        return n;
    }
};
