class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans; ans.push_back({rStart, cStart});
        
        int cnt = rows * cols -1;
        
        int  deg = 1;
        int direction = 1;
        
        while(cnt){
            int v = deg;
            
            while(v){
                if(direction){
                    cStart++;
                }
                else {
                    cStart--;
                }
                v--;
                
                if(0<= cStart && cStart < cols && 0<= rStart && rStart < rows ){
                    ans.push_back({rStart, cStart});
                    cnt--;
                }
            }
                
            v = deg;
            while(v){
                if(direction){
                    rStart++;
                }
                else {
                    rStart--;
                }
                v--;
                
                if(0<= rStart && rStart < rows && 0<= cStart && cStart < cols){
                    ans.push_back({rStart, cStart});
                    cnt--;
                }
            }
            
            deg++;
            
            direction ^= 1;
            
        }
        return ans;
    }
};