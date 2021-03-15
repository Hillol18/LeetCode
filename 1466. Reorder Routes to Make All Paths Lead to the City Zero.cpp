class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<int>>d(n);
        vector<vector<int>>dr(n);

        vector<int>visit(n,0);
        for(int i=0;i<connections.size();i++){
            d[connections[i][1]].push_back(connections[i][0]);
            dr[connections[i][0]].push_back(connections[i][1]);
        }

        queue<int> qu;
        qu.push(0);
        visit[0]=1;

        int cnt =0;
        while(!qu.empty()){
            int top = qu.front();
            qu.pop();
            for(int i=0;i<d[top].size();i++){
                if(visit[d[top][i]]) continue;
                qu.push(d[top][i]);
                visit[d[top][i]] = 1;
            }

            for(int j=0;j<dr[top].size();j++){
                if(visit[dr[top][j]]) continue;

                cnt++;
                //cout<<top<<" "<<dr[top][j]<<endl;
                visit[dr[top][j]] = 1;
                qu.push(dr[top][j]);
            }
        }

        return cnt;

    }
};
