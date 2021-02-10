class Solution {
public:

    int rr[4]={-1, 0, 1, 0};
    int cc[4]={ 0, 1, 0,-1};


    int dfs(int r, int c, vector<vector<int>> &dp, int &rs, int &cs, vector<vector<int>> &data){

        int &ret = dp[r][c];
        if(ret !=-1)
            return ret;
        ret = 0;
        for(int i=0;i<4;i++){
            int nr = rr[i]+r;
            int nc = cc[i]+c;

            if(nr<0 || nc < 0 || nc>=cs || nr>=rs)
                continue;
            if(data[r][c]>= data[nr][nc])
                continue;
            ret = max(ret, 1+dfs(nr,nc,dp, rs,cs, data));

        }
        //ret+=1;
        return ret;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rs=matrix.size();

        int cs = 0;
        if(rs){
            cs = matrix[0].size();
        }

        vector<vector<int>> dp(rs, vector<int>(cs,-1));
        int ans =0;
        for(int i=0;i<rs;i++){
            for(int j=0;j<cs;j++){
                ans = max(ans,1+dfs(i,j,dp,rs,cs, matrix));

            }
        }
        return ans;
    }
};
