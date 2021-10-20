class Solution {
public:
    
    
    void dfs(int r, int c, int &rr, int &rc, vector<vector<char>>& board){
        //if(r < 0 || c < 0 || r >= rr || c >= rc || board[r][c] == 'B'){
          //  return;
        //}
        
        if(board[r][c] == 'M'){
            board[r][c] ='X';
            return;
        }
        
        int mineCnt = 0;
        
        int wr = min(r+1, rr-1);
        int wc = min(c+1, rc-1);
        for(int i = max(r-1, 0); i <= wr; i++){
            for(int j = max(c-1, 0); j <= wc; j++){
               mineCnt += (board[i][j] == 'M' ? 1 : 0);
            }
        }
        
        if(mineCnt){
            board[r][c] = '0' + mineCnt;
            return;
        }
        
        
        board[r][c] = 'B';
        for(int i = max(r-1, 0); i <= wr; i++){
            for(int j = max(c-1, 0); j <= wc; j++){
               if(board[i][j] == 'E'){
                   dfs(i, j, rr,rc, board);
               }
            }
        }
        
        board[r][c] = 'B';
        
        
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = board.size();
        int c = board[0].size();
        dfs(click[0], click[1], r, c, board);
        return board;
    }
};