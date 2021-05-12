class Solution {
public:

    bool isTrue(int n, int pos) {
        return (n&(1<<pos));
    }

    void setTrue(int &n, int pos){
        n|=(1<<pos);
    }

    void setFalse(int &n, int pos){
        n = n & (~(1<<pos));
    }

    int getIndex(int r, int c){
        if(0<=r && r<=2){
            if(0<=c && c<=2) return 1;
            if(3<=c && c<=5) return 2;
            if(6<=c && c<=8) return 3;

        }

        if(3<=r && r<=5){
            if(0<=c && c<=2) return 4;
            if(3<=c && c<=5) return 5;
            if(6<=c && c<=8) return 6;
        }

        else{
            if(0<=c && c<=2) return 7;
            if(3<=c && c<=5) return 8;
            if(6<=c && c<=8) return 9;
        }
        return 0;
    }

    int help(int r, int c){
       return getIndex(r, c)-1;
    }

    bool dfs(int r, int c, vector<vector<char>>& board, vector<int> &row, vector<int> &col, vector<int> &block) {

        if(r==9) return true;
        if(c==9) return dfs(r+1, 0, board, row, col, block);
        if(board[r][c] != '.') return dfs(r, c+1, board, row, col, block);
        int idx= help(r,c);
        //cout<<idx<<endl;
        for(int i=1;i<=9;i++){
            if(!isTrue(row[r], i) && !isTrue(col[c], i) && !isTrue(block[idx],i)){
                setTrue( row[r], i);
                setTrue( col[c], i);
                setTrue( block[idx], i);
                board[r][c] = (i+'0');
                bool rt = dfs(r, c+1, board, row, col, block );
                if(rt) return true;
                board[r][c] = '.';
                setFalse( block[idx], i);
                setFalse( row[r], i);
                setFalse( col[c], i);
            }
        }
        return false;
    }


    void solveSudoku(vector<vector<char>>& board) {
            vector<int> row(9,0);
            vector<int> col(9,0);
            vector<int> block(9,0);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9 ; j++){
                if(board[i][j] != '.'){
                    int ch = board[i][j]-'0';
                    row[i]|=(1<<(ch));
                    col[j]|=(1<<(ch));
                    int idx = help(i,j);

                    block[idx]|=(1<<(ch));
                }
            }
        }

        int r = dfs(0, 0, board, row, col, block);
        //cout<<r<<endl;
    }
};
