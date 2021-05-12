class NumMatrix {
public:
    vector<vector<int>> preSum;

    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        preSum.resize(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                preSum[i][j] = matrix[i][j];
                if(j>0)
                    preSum[i][j] += preSum[i][j-1];

                if(i>0)
                    preSum[i][j] += preSum[i-1][j];

                if(i>0 && j>0) preSum[i][j] -= preSum[i-1][j-1];

            }
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        int sum = preSum[row2][col2];

        //cout<<sum<<endl;

        if(row1>0) sum-= preSum[row1-1][col2];

        if(col1>0) sum-= preSum[row2][col1-1];

        if(row1 >0 && col1 >0 ) sum+= preSum[row1-1][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 INT_MIN  +
    00010000
    11101111




    --00000101000
    --11111010111
    INT_MIN(2^31) + 2^30 * 1 + 2^29*1 = -41
 */
