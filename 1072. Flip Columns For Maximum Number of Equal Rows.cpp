class Solution {
public:

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
       unordered_map<string, int> u_mp;
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            string s,rs;
            rs = s = "";
            for(int j = 0; j<m; j++){
                if(matrix[i][j]){
                    s += "1";
                    rs += "0";
                }
                else{
                    s += "0";
                    rs += "1";
                }
                
            }
            u_mp[s]++;
            u_mp[rs]++;
            ans = max(ans, u_mp[rs]);
        }
        return ans;
    }
};