class Solution {
public:

    int help(int pos,int b, int tr, vector<int>&data, vector<vector<vector<int>>> &dp){

        if(pos==data.size()){
          return 0;
        }

        int &ret = dp[pos][b][tr];

        if(ret !=-1) return ret;
        ret = 0;
        if(b && tr>0){
          ret = max(ret, data[pos]+ help(pos+1, !b, tr-1, data,dp));
        }
        else if(tr>0){
          ret = max(ret, help(pos+1, !b, tr, data,dp) - data[pos]);
        }

        ret = max(ret, help(pos+1,b,tr,data, dp));
        return ret;
    }

    int useDP(vector<int>&prices, int n){
         vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3,-1)));

        return help(0,0,2,prices,dp);
    }

    int iterative(vector<int>&prices, int n){

        int r1=0,r2=0;
        int h1=INT_MIN,h2=INT_MIN;
        for(int i=0;i<n;i++){

            r2=max(r2, prices[i]+h2);
            h2=max(h2,r1-prices[i]);

            r1=max(r1, prices[i]+h1);
            h1=max(h1, -prices[i]);

        }
        return r2;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int ans = 0;
        if(!n) return ans;


        ans = iterative(prices,n);
        return ans;
    }
};
