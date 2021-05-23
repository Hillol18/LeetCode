/*Hillol*/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();

        queue<pair<int, int>> qu;
        int r[4] = {-1, 0, 1, 0};
        int c[4] = { 0, 1, 0,-1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(rooms[i][j] == 0) qu.push(make_pair(i,j));
            }
        }

        while(!qu.empty()){

            auto it =  qu.front();
            qu.pop();

            for(int i=0; i<4; i++){
               int nr = it.first + r[i];
               int nc = it.second + c[i];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m || rooms[nr][nc] != INT_MAX) continue;

                rooms[nr][nc] = rooms[it.first][it.second] + 1;
                qu.push(make_pair(nr,nc));
            }
        }
    }
};
