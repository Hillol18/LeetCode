class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visit(n);
        int count = 0;
        queue<int> qu;
        for(int i=0;i<n;i++){

            if(visit[i])
                continue;

            qu.push(i);
            count++;
            while(!qu.empty()){
                int cur = qu.front();
                qu.pop();
                visit[cur] = 1;
                for(int i=0;i<isConnected[cur].size();i++){
                    if(i==cur) continue;
                    if(isConnected[cur][i] == 0 || visit[i]) continue;

                    qu.push(i);

                }

            }

        }
        return count;
    }
};
