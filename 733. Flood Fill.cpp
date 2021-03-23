class Solution {
public:

    bool isSafe(vector<vector<int>> &image, int r,int c, int sr,int sc, int clr){
        if(r<0 || c<0 || r>=sr || c>=sc) return false;
        if(image[r][c] != clr) return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};

        int n = image.size();
        if(!n) return image;
        int m = image[0].size();
        int c = image[sr][sc];
        if(c == newColor) return image;

        image[sr][sc] = newColor;
        queue<pair<int,int>> qu;
        qu.push(make_pair( sr, sc));
        while(!qu.empty()){
            auto it = qu.front();
            qu.pop();

            for(int i=0;i<4;i++){
                int nr = dr[i]+it.first;
                int nc = dc[i]+it.second;
                if(!isSafe(image, nr,nc,n,m, c)) continue;
                image[nr][nc] = newColor;

                qu.push(make_pair(nr,nc));
            }

        }
     return image;
    }
};
