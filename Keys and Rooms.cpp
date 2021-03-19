class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        queue<int> qu;


        int cnt = rooms.size();
        vector<bool> visit(cnt);

        qu.push(0);
        cnt--;
        visit[0]=true;
        while(!qu.empty()){
            int cur = qu.front();
            qu.pop();
            for(int i=0;i<rooms[cur].size();i++){
                if(visit[rooms[cur][i]]) continue;
                visit[rooms[cur][i]]= true;
                cnt--;
                qu.push(rooms[cur][i]);
            }

        }

        return (cnt == 0);
    }
};
