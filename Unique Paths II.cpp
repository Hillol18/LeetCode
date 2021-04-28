class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        if(n==0) return 0;

        int m = obstacleGrid[0].size();
        vector<int> pre(m,0), cur(m,0);

        pre[0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j] == 1) cur[j]=0;
                else{
                    cur[j]+=pre[j];
                    if(j) cur[j]+=cur[j-1];
                }
            }

            for(int j=0;j<m;j++){
                pre[j]=cur[j];
                cur[j]=0;
            }
        }
        return pre[m-1];
    }
};
