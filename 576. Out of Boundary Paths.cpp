class Solution {
public:
    
    vector<int> rr = {0,-1, 0, 1};
    vector<int> cc = {-1,0, 1, 0};
    
    bool outOfBoundary(int r,int c, int m, int n){
        return  r < 0 || c < 0 || r == m || c == n;
    }
    int md = 1000000007;
    int dfs(int move, int r, int c, int m, int n, vector<vector<vector<int>>> &dp){
        if(move == 0) return 0;
        
        int &ret = dp[move][r][c];
        
        if(ret !=-1) return ret;
        ret = 0;
        
        for(int i=0; i< 4; i++){
            int nr = r + rr[i];
            int nc = c + cc[i];
            if(outOfBoundary(nr,nc, m,n)){
                ret++;
                continue;
            }
            ret += dfs(move-1, nr, nc, m, n, dp);
            if(ret >= md) ret %= md;
        }
        
        return ret;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m, vector<int>(n,-1)));
        
        int ans = dfs(maxMove,startRow, startColumn, m, n, dp);
        return ans;
    }
};