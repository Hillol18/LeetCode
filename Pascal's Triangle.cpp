class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>());
        ans[0].push_back(1);
        int pre = 0;
        for(int i = 1; i < numRows; i++){
            pre = 0;
            for(int j = 0; j <= i; j++){
                ans[i].push_back( (i == j? 0 : ans[i-1][j]) + pre);
                pre = i == j? 0 : ans[i-1][j];
            }
        }
        return ans;
    }
};