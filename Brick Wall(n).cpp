class Solution {
public:

    int leastBricks(vector<vector<int>>& wall) {
       unordered_map<int,int> mp;
        int ans = wall.size();
        int n = wall.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<wall[i].size();j++){
                if(j+1 < wall[i].size()){
                    sum+=wall[i][j];
                    mp[sum]++;
                    ans = min(ans, n-mp[sum]);
                }
            }
        }
        return ans;
    }
};
