class Solution {
public:
    vector<int> row= { 0,-1, 0, 1};
    vector<int> col= {-1, 0, 1, 0};

    bool isSafe(int r,int c,int rr,int cc, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(r>=matrix.size()) return false;
        if(c>= matrix[0].size()) return false;
        if(matrix[rr][cc] >= matrix[r][c]) return false;
        return true;
    }

    int dfs(int r,int c, vector<vector<int>> &matrix, vector<vector<int>> &dp){

        int &ret = dp[r][c];

        if(ret !=-1) return ret;
        ret = 1;
        for(int i=0;i<4;i++){
            int nr = r + row[i];
            int nc = c + col[i];
            if(!isSafe(nr,nc,r,c,matrix,dp)) continue;
            ret = max(ret, 1+ dfs(nr,nc, matrix, dp));
        }
        return ret;
    }


    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==0) return 0;

        int m = matrix[0].size();

        vector<vector<int>> visit(n, vector<int>(m,-1));
        int ans= 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visit[i][j] ==-1){
                   ans = max(ans, dfs(i,j,matrix,visit));
                }
            }
        }
        return ans;
    }
};
