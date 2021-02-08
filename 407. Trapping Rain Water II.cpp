/**

Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.

The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.



After the rain, water is trapped between the blocks. The total volume of water trapped is 4.
**/

class Solution {
public:

    struct node{
        int r,c;
        int v;
        node(){}
        node(int rr,int cc,int vv){
            r=rr;
            c=cc;
            v=vv;
        }
    };

    struct cmp{
        bool operator()(node a, node b){
            return a.v > b.v;
        }
    };


    int trapRainWater(vector<vector<int>>& heightMap) {

        int row = heightMap.size();
        if(row==0)
            return 0;
        int col = heightMap[0].size();


        int visit[row+1][col+1];
        memset(visit, 0, sizeof(visit));

        priority_queue<node, vector<node>, cmp> qu;

        for(int i=1;i<col-1;i++){
            visit[0][i] = 1;
            qu.push(node(0, i, heightMap[0][i]));
            visit[row-1][i] = 1;
            qu.push(node(row-1, i,heightMap[row-1][i]));
        }

        for(int i=0;i<row;i++){
            visit[i][0] = 1;
            qu.push(node(i, 0, heightMap[i][0]));
            visit[i][col-1] = 1;
            qu.push(node(i, col-1,heightMap[i][col-1]));

        }

        int mx = -1;
        int ans = 0;
        int dr[]={ 0,-1, 0, 1};
        int dc[]={-1, 0, 1, 0};
        while(!qu.empty()){
       //     cout<<qu.top().r<<" "<<qu.top().c<<" "<<qu.top().v<<"  "<<endl;
            int nr,nc;
            node top = qu.top();
            qu.pop();
            for(int i=0;i<4;i++){
                nr = top.r + dr[i];
                nc = top.c + dc[i];
                if(nr<0 || nr>=row)
                    continue;
                if(nc<0 || nc>=col)
                    continue;

                if(visit[nr][nc])
                    continue;
               // cout<<" + "<<nr<<" "<<nc<<endl;
                visit[nr][nc] = 1;
                qu.push(node(nr, nc, heightMap[nr][nc]));
            }


            if(top.v < mx){
                ans+=(mx-top.v);
               // cout<<"ans "<<ans<<endl;
            }
           // cout<<"t "<<qu.top().v<<endl;
             mx = max(mx,top.v);
            //cout<<"mx "<<mx<<endl;

        }
       return ans;
    }
};
