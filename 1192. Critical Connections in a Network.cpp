class Solution {
public:


    int dfs(int pos, int &time, vector<int> &visit, vector<vector<int>> &graph, vector<int> &d, vector<int> &l, vector<vector<int>> &st, int pre){
        //cout<<" pos "<<pos<<endl;
        visit[pos]=1;
        l[pos]=d[pos]=time++;

        vector<int> temp(2);
        temp[0]=pos;

        for(int i=0;i<graph[pos].size();i++){
            if(graph[pos][i]==pre) continue;

            if(visit[graph[pos][i]]){
                l[pos]=min(l[pos], d[graph[pos][i]]);
            }else{
               int x = dfs(graph[pos][i], time, visit, graph, d, l,st, pos);

                l[pos]=min(l[pos], x);
            }
        }

        if(d[pos]==l[pos] && pre !=-1){
            temp[1]=pre;
            st.push_back(temp);
        }

        //cout<<pos<<" "<<d[pos]<<" "<<l[pos]<<endl;
        return l[pos];
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        vector<vector<int>> graph(n);

        for(int i=0;i<len;i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int>visit(n,0);
        vector<int>low(n,INT_MAX);
        vector<int>descovertime(n);

        int time=1;
        vector<vector<int>>st;
        dfs(0, time, visit, graph, descovertime, low, st,-1);
        return st;
    }
};
