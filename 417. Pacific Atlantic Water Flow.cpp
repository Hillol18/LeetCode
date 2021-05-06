class Solution {
public:


    void bfs(int r, int c, vector<vector<int>> &visit, int v, vector<vector<int>> &data){
        queue<pair<int,int>> qu;
        qu.push(make_pair(r,c));
        visit[r][c] += v;

        int rr[4]={ 0,-1, 0, 1};
        int cc[4]={-1, 0, 1, 0};

        while(!qu.empty()){
            auto it = qu.front();
            qu.pop();
            for(int i=0;i<4;i++){
                int nr = it.first + rr[i];
                int nc = it.second + cc[i];

                if(nr<0 || nc < 0 || nc>=visit[0].size() || nr>=visit.size()) continue;

                if(data[it.first][it.second]> data[nr][nc]) continue;


                if(visit[nr][nc] == v || visit[nr][nc] >3) continue;

                visit[nr][nc] +=v;

                qu.push(make_pair(nr,nc));

            }

        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans;
        if(n==0) return ans;
        int m = matrix[0].size();
        //cout<<n<<" "<<m<<endl;
        vector<vector<int>> visit(n, vector<int>(m,0));

        //bfs(0,0,visit,1);

        for(int i=0;i<m;i++){
            if(!visit[0][i])
            bfs(0,i,visit,1,matrix);
        }

        for(int i=0;i<n;i++){
            if(!visit[i][0])
                bfs(i,0,visit,1,matrix);
        }

        for(int i=0;i<m;i++){
            if(visit[n-1][i]!=2){
                bfs(n-1,i,visit,2, matrix);
            }
        }

        for(int i=n-1;i>=0;i--){
            if(visit[i][m-1]!=2){
                bfs(i,m-1,visit,2, matrix);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //cout<<visit[i][j]<<" ";
                if(visit[i][j] >=3 ){
                    ans.push_back({i,j});
                }
            }
            //cout<<endl;
        }

        return ans;
    }
};
