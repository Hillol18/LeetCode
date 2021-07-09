class Solution {
public:
    
    pair<int, int> dfs(int pos, int parent, vector<vector<int>> &g, vector<vector<int>> &edge){
        //cout<<pos <<" "<< parent <<endl;
        auto ret = make_pair(0,1); 
        for(int i=0; i<g[pos].size(); i++){
            if(edge[g[pos][i]][1] == parent) continue;
            if( edge[g[pos][i]].size() == 2){
                auto temp = dfs(edge[g[pos][i]][1], pos, g, edge);
                edge[g[pos][i]].push_back( temp.first + temp.second);
                edge[g[pos][i]].push_back( temp.second);
            }
            ret.first +=  edge[g[pos][i]][2];
            ret.second +=  edge[g[pos][i]][3];
            
        }
        
        return ret;
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gr(n);
        vector<int> ans(n, 0);
        for(int i = 0; i< (n-1); i++){
            gr[edges[i][0]].push_back(i);
            
            edges.push_back({edges[i][1], edges[i][0]});
            
            gr[edges[i][1]].push_back(n+i-1);
        }
        
        for(int i=0; i< (2*n - 2); i++){
            if(edges[i].size() == 2){
                //cout<<"in "<<i<<endl;
                auto it = dfs(edges[i][1], edges[i][0], gr, edges);
                //cout<<"done"<<endl;
                edges[i].push_back(it.first + it.second);
                edges[i].push_back(it.second);
            }
            
            ans[edges[i][0]] += edges[i][2];
        }
        
        return ans;
    }
};