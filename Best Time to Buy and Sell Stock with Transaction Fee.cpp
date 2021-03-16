class Solution {
public:

    int help(int pos, int state, vector<vector<int>> &dp, vector<int> &input, int &fee){
        if(pos == input.size()){
            return 0;
        }
        int &ret = dp[pos][state];
        if(ret !=-1) return ret;
        ret = 0;
        if(state){
            ret = max(ret, input[pos] - fee + help(pos+1, !state, dp, input, fee));
        }
        else {
            ret = max(ret, -input[pos] + help(pos+1, !state, dp, input, fee));
        }

        ret = max(ret, help(pos+1, state, dp, input, fee));

        return ret;
    }

    int maxProfit(vector<int>& prices, int fee) {

        int n =  prices.size();
        //vector<vector<int>> dp(n, vector<int>(2,-1));
        //help(0, 0, dp, prices, fee);

        int buy = -prices[0], sel=0;
        for(int i=1;i<n;i++){
            int s = buy + prices[i] - fee;
            int b = sel - prices[i];

            buy=max(buy, b);
            sel=max(sel, s);
        }


        return sel;
    }
};
