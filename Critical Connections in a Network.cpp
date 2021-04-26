class Solution {
public:

    int dfs(int cur, int pre, vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &disc, vector<int> &low, int &time){

        //cout<<cur<<" "<<pre<<endl;
        if(low[cur]) return low[cur];

        disc[cur]=low[cur]=time++;

        for(int i=0;i<graph[cur].size();i++){
            int node = graph[cur][i];
            if(node == pre) continue;

          low[cur] = min(low[cur], dfs(node, cur, graph, ans, disc, low, time));
        }

        if(low[cur] == disc[cur] && pre !=-1){
            ans.push_back({pre, cur});
        }
        return low[cur];
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        int m = connections.size();
        for(int i=0;i<m;i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> discoverTime(n,0);
        vector<int> low(n,0);
        vector<vector<int>> ans;
        int time=1;
        dfs(0, -1 , graph, ans, discoverTime, low, time);
        return ans;
    }
};
