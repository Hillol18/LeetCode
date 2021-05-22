/*
[
[-1,1 , 2,-1],
[ 2,13,15,-1],
[-1,10,-1,-1],
[-1,6 , 2, 8]]
*/
struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
};

class Solution {
public:

    pair<int, int> getCoordinate(int cellNo, int r, int c){
        int row = cellNo / c;
        row -= (row * c == cellNo);

        if(row){
            cellNo -= (row)*c;
        }

        int col = cellNo - 1;

        if(row%2) col = c-1-col;

        row = r-1-row;
        return make_pair(row, col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {


        //priority_queue< pair<int,int>, vector<pair<int,int>>, cmp > qu;
       // cout<<"start"<<endl;
        queue<pair<int,int>> qu;
        int n = board.size();

        if(!n) return -1;

        int m = board[0].size();


        vector<int> cost(n*m+1, INT_MAX);
        cost[1] = 0;
        qu.push(make_pair(1,0));
        while(!qu.empty()){
           auto it = qu.front();

            qu.pop();
            for(int i=1; i <= 6; i++){
                int next = it.first+i;
                if(next<=(n*m)){
                    auto temp = getCoordinate(next,n,m);

                    if(board[temp.first][temp.second] != -1){
                        next = board[temp.first][temp.second];
                    }

                    int nextCost = it.second + 1;
                    if(cost[next] > nextCost){
                        cost[next] = nextCost;
                        qu.push(make_pair(next, nextCost));
                    }
                }
            }
        }
        return cost[n*m] == INT_MAX ? -1 : cost[n*m];
    }
};
