class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> dependency(numCourses);
        vector<vector<int>> graph(numCourses);
        int n = prerequisites.size();
        for(int i=0;i<n;i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            dependency[prerequisites[i][1]]++;
        }
        queue<int>qu;
        for(int i=0;i<numCourses;i++){
            if(dependency[i]==0) qu.push(i);
        }
        numCourses-=qu.size();

        while(!qu.empty()){
            int x = qu.front();
            qu.pop();
            for(int i=0;i<graph[x].size();i++){
                dependency[graph[x][i]]--;
                if(dependency[graph[x][i]]==0){
                    qu.push(graph[x][i]);
                    numCourses--;
                }

            }
        }
        return numCourses == 0;
    }
};
