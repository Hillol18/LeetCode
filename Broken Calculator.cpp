class Solution {
public:

    int help(int x, int y){

        if(x>=y)
            return x-y;
        int ans=0;
        if(y%2){
            ans =1+help(x, y+1);
        }
        else{
            ans =1+help(x, y/2);
        }

        return ans;
    }

    int brokenCalc(int X, int Y) {
       return  help(X,Y);
    }
};
