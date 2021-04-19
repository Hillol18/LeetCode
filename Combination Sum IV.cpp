class Solution {
public:
    int help(int sum, vector<int> &nums, vector<int> &dp){
        if(sum==0) return 1;
        if(sum<0) return 0;
        int &ret = dp[sum];
        if(ret !=-1) return ret;
        ret = 0;
        for(int i=0;i<nums.size();i++){
            ret += help(sum- nums[i], nums, dp);
        }

        return ret;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target +1, -1);
        return help(target, nums, dp);
    }
};
