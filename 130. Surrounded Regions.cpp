class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> visit(n, vector<int>(m, 0));
        queue<pair<int, int>> qu;
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O')
            {
                qu.push(make_pair(i, 0));
                board[i][0] = 'a';
            }
            if(m > 1 && board[i][m-1] == 'O'){
                qu.push(make_pair(i, m-1));
                board[i][m-1] = 'a';
            }
            
        }

        for(int i=0; i<m; i++){

            if(board[0][i] == 'O'){
                qu.push(make_pair(0, i));
                board[0][i] = 'a';
            }
            
            
            if(n > 1 && board[n-1][i] == 'O'){
                qu.push(make_pair(n-1, i));
                board[n-1][i] = 'a';
            }
            
        }
        
        vector<int> r = { 0,-1, 0,1};
        vector<int> c = {-1, 0, 1,0};
        
        while(!qu.empty()){
            auto it = qu.front();
          
            qu.pop();
            for(int i = 0; i<4 ; i++){
                int nr = it.first + r[i];
                int nc = it.second + c[i];
                
                if(nr < 0 || nr >= n || nc < 0 || nc >= m || board[nr][nc] != 'O') continue;
                board[nr][nc] = 'a';
                qu.push(make_pair(nr, nc));
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == 'a') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};