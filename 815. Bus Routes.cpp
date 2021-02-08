

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int nr=routes.size();
        unordered_map<int,vector<int>>g;

        for(int i=0;i<nr;i++){
            for(int j=0;j<routes[i].size();j++){
                g[routes[i][j]].push_back(i);
            }
        }

        unordered_set<int>visit;

        int level=0;

        queue<int> qu;

        qu.push(source);

        if(source==target) return 0;

        while(!qu.empty()){

            level++;

            int len = qu.size();

            while(len){
                int cur = qu.front();
                qu.pop();
                len--;

                for(int i=0;i<g[cur].size();i++){
                    int bus =g[cur][i];
                    if(visit.find(bus)==visit.end()){
                        visit.insert(bus);

                        for(int j=0;j<routes[bus].size();j++){
                            if(routes[bus][j] == target) return level;
                            qu.push(routes[bus][j]);
                        }
                    }
                }
            }


        }
        return -1;

    }
};
