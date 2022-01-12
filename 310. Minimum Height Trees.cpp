/*
7
[[0,1],[1,2],[1,3],[2,4],[3,5],[4,6]]

0-1-2-4-6
  |
  3-5
 
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0);
        vector<vector<int>>grid(n);
        
        vector<int> ans;
        vector<int> visit(n,0);
        
        int mn = n;
        for(auto it: edges){
            deg[it[0]]++;
            deg[it[1]]++;
            grid[it[0]].push_back(it[1]);
            grid[it[1]].push_back(it[0]);
        }
        
        queue<int> qu;
        
        int cnt = n;
        for(int i = 0; i<n; i++){
            mn = min(mn, deg[i]);
        }
        
        for(int i = 0; i<n; i++){
            if(deg[i] == mn){
                qu.push(i);
                visit[i] = 1;
            }
        }
           
        while(qu.size() != cnt && cnt > 0){
            
            int d = qu.size();
            //cout<<d<<endl;
            cnt -= d;
            
            while(d--){
                int x = qu.front();
                
                for(int i = 0; i<grid[x].size(); i++){
                    int y = grid[x][i];
                    if(visit[y] == 0){
                        deg[y]--;
                        if(deg[y] == 1){
                            qu.push(y);
                            visit[y] = 1;
                        }
                    }
                }
                qu.pop();
            }
            
        }
        
        while(!qu.empty()){
            ans.push_back(qu.front());
            qu.pop();
        }
        return ans;
    }
};