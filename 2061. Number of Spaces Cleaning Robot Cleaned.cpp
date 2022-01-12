/*Nafiul

[
[0,0,0,1],
[0,1,0,1],
[1,0,0,0]]

*/
class Solution {
public:
    vector<int> rd {0, 1, 0,-1};
    vector<int> cd {1, 0,-1, 0};
    
    int getCleanedRoom(int r, int c, vector<vector<int>>& room, int cur, int &ans){

        if(room[r][c] == 0){
            ans++;
        }
        
        if(cur == 4){
         cur = 0;   
        }
        
        if(room[r][c] & (1<<(cur + 1))) return 0;
        room[r][c] |= (1<<(cur + 1));
                
        int nr = r + rd[cur];
        int nc = c + cd[cur];
        
        if(nr < 0 || nc < 0 || nr >= room.size() || nc >= room[0].size() || room[nr][nc] == 1){     
             getCleanedRoom(r, c, room, cur + 1, ans);
        }
        else{
           getCleanedRoom(nr, nc, room, cur, ans);
        }
        
        return ans;
    }
    
    
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int n = room.size();
        int m = room[0].size();
        int ans = 0;
        getCleanedRoom(0,0, room, 0, ans);
        return ans;
    }
};
