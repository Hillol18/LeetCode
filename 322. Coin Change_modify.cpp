class Solution {
public:

    int mx = 0;
    int dp[100][100000];
    int n;
    int fun(int pos,int v, vector<int>& coins){
        if(pos==n){
            if(v==0)
            return 0;
            return mx;
        }

        int &ans = dp[pos][v];

        if(ans !=-1)
            return ans;
        ans = mx;

        if(v-coins[pos]>=0){
          ans =min(ans,  1 + fun(pos, v-coins[pos], coins));
        }

        ans = min(ans, fun(pos+1,v, coins));

        return ans;

    }

    int interative(vector<int> &coins, int amount){
        vector<int> dp(amount+1, amount+2);
        dp[0]=0;

        for(int i=0;i<coins.size();i++){
                for(int j=coins[i];j<=amount;j++){
                    dp[j] = min(dp[j], dp[j-coins[i]]+1);
                }
        }
        return dp[amount] > amount ? -1 : dp[amount] ;

    }

    int coinChange(vector<int>& coins, int amount) {
        mx = amount+2;
        memset(dp,-1, sizeof(dp));
        n = coins.size();
        int res = interative(coins, amount);
        //int res = fun(0, amount, coins);
        return res;
    }
};
