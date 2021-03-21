class Solution {

public:

    bool isSafe(vector<vector<int>> &forest, int r, int c,int rr,int cc, vector<vector<int>> &visit){
        if(r<0 || r>=rr || c<0 || c>=cc) return false;
        if(forest[r][c] == 0) return false;

        if(visit[r][c]) return false;
        return true;
    }

    int bfs(vector<vector<int>> &forest, int sr, int sc, int tr, int tc){

        int r = forest.size();
        int c = forest[0].size();
        //cout<<sr<<" "<<sc<<" "<<tr<<" "<<tc<<endl;
        vector<vector<int>> visit(r, vector<int>(c, 0));

        int dr[4]= {-1, 0, 1, 0};
        int dc[4]= {0,  1, 0, -1};


        visit[sr][sc] = 1;
        queue<pair<int,int>> qu;
        int step = 0;
        qu.push(make_pair(sr,sc));
        if(tr == sr && tc == sc) return 0;
        while(!qu.empty()){

            int sz = qu.size();

            step++;
            while(sz--){
                auto it = qu.front();
                qu.pop();

                for(int i=0;i<4;i++){
                    int nr = dr[i]+ it.first;
                    int nc = dc[i]+ it.second;
                    if(!isSafe(forest, nr,nc,r,c, visit)) continue;

                    if(nr == tr && nc == tc) return step;
                    visit[nr][nc] = 1;
                    qu.push(make_pair(nr,nc));
                }
            }
        }


        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
       int ans = 0;

        int n = forest.size();
        if(!n) return 0;
        int m = forest[0].size();

        vector<vector<int>> tree;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j] > 1 ){
                    tree.push_back({forest[i][j],i,j});
                }
            }
        }

        sort(tree.begin(), tree.end());

        int sz = tree.size();
        cout<<sz<<endl;
        int r=0,c=0;

        for(int i=0;i<sz;i++){
           int x = bfs(forest, r,c, tree[i][1], tree[i][2]);
           if(x<0) return -1;
            ans +=x;
           // cout<<ans<<endl;
           r = tree[i][1];
           c = tree[i][2];
        }


        return ans;
    }
};
