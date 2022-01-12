/*
[[1,1,1]
,[1,0,1]
,[1,1,1]]
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool row = 0;
        
        bool col = 0;
        
        for(int i =0; i<n; i++) col |= (matrix[i][0] == 0);
        for(int j =0; j<m; j++) row |= (matrix[0][j] == 0);
        
        for(int i = 0; i<m; i++){
            bool isZero = false;
            for(int j = 0; j<n; j++){
                isZero |= (matrix[j][i] == 0);
            }
            if(isZero){
                matrix[0][i] = 0; 
            }
            
        }
        
        for(int i = 1; i<n; i++){
            bool isZero = false;
            for(int j = 0; j<m; j++){
                isZero |= (matrix[i][j] == 0);
            }
            if(isZero)
                matrix[i][0] = 0;
        }
        
        for(int i= 1; i<n; i++)
            for(int j = 1; j<m; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        
        
        for(int i =0; i<n && col; i++) matrix[i][0] = 0;
        for(int j =0; j<m && row; j++) matrix[0][j] = 0;

    }
};