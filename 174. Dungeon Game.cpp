/*

-2 -3   3
-5 -10  1
10  30 -5

*/


class Solution {
public:
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        vector<vector<int>> data(n+1, vector<int>(m+1, -100000));
        
        if(dungeon[n-1][m-1] > 0) 
            data[n-1][m-1] = 0;
        else
            data[n-1][m-1] = dungeon[n-1][m-1];
            
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(i == n-1 && j == m-1) continue;
                data[i][j] = dungeon[i][j] + max(data[i][j+1], data[i+1][j]);        
                if(data[i][j] > 0) data[i][j] = 0;
                
            }
        }

        int ans = 0;
        if(data[0][0]<=0) ans = 1 + abs(data[0][0]);
        
        return ans;
    }
};