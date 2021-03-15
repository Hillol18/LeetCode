class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {

        int n = arr.size();

        sort(arr.begin(), arr.end());

        unordered_map<int,int>mp;

        vector<long> dp(n, 1);

        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }

        long ans = 0;
        long md = 1000000007;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j] == 0){
                    int d = arr[i]/arr[j];
                    if(mp.find(d) != mp.end()){
                       dp[i]+= (dp[j] * dp[mp[d]]); //* (d == arr[j]?1:2);

                      dp[i]%=md;
                    }
                }
            }
            ans += dp[i];
                ans %=md;
        }

        return ans;
    }
};
