class Solution {
public:


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rs = grid.size();
        if(!rs) return -1;

        int cs = grid[0].size();

        int dr[8]={-1,-1,0,1,1, 1, 0,-1};
        int dc[8]={ 0, 1,1,1,0,-1,-1,-1};

        queue<pair<int,int>> qu;

        if(grid[0][0]==1) return -1;
        qu.push(make_pair(0,0));
        grid[0][0]=1;
        //visit[0][0]=1;
        while(!qu.empty()){
            pair<int,int> temp = qu.front();
            if(temp.first ==  rs-1 && temp.second == cs-1) return grid[temp.first][temp.second];
            qu.pop();
            for(int i=0;i<8;i++){
                int nr = temp.first + dr[i];
                int nc = temp.second +dc[i];
                if(nc<0 || nc>= cs || nr<0 || nr>= rs) continue;
                if(grid[nr][nc]) continue;
                grid[nr][nc] = grid[temp.first][temp.second]+1;
                qu.push(make_pair(nr,nc));
            }
        }

     return -1;
    }
};
