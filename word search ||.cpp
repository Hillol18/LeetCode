class Solution {
public:

    struct node {
        int cnt=0;
        string word;
        node *child[26];
    };


    void insertinTrie(node *r, string &word){
        for(int i=0;i<word.size();i++){
            int idx = word[i]-'a';

            if(!r->child[idx]){
                r->child[idx] = new node();
            }
            r->child[idx]->cnt++;
            r = r->child[idx];
        }
        r->word= word;
    }

    node* buildTrie(vector<string>&words){
        node *r = new node();
        for(int i=0;i<words.size();i++){
            insertinTrie(r, words[i]);
        }
        return r;
    }

    void removeTrie(node *r, string word){
        for(int i=0;i<word.size();i++){
            int idx = word[i]-'a';
            r->child[idx]->cnt--;
            r=r->child[idx];
        }
        r->word="";
    }

    bool isSafe(int &r, int &c, vector<vector<char>>&board, node *rr){
        if(r>=board.size() || r<0) return false;
        if(c>=board[0].size() || c<0) return false;

        if(board[r][c] =='*') return false;

         if(!rr->child[board[r][c] - 'a']) return false;

         if(rr->child[board[r][c] - 'a']->cnt==0) return false;
        return true;
     }

    void dfs(int r, int c, vector<vector<char>> &board, vector<string> &ans, node *root,node *r_root){
        vector<int> rr = {-1, 0, 1, 0};
        vector<int> cc = { 0, 1, 0,-1};

        if(root->word.size()) {
            ans.push_back(root->word);
            removeTrie(r_root, root->word);

        };
        char ch = board[r][c];
        board[r][c] = '*';
        for(int i=0;i<4;i++){
            int nr = r + rr[i];
            int nc = c + cc[i];
            if(!isSafe(nr,nc,board, root)) continue;
            dfs(nr,nc, board, ans, root->child[board[nr][nc]-'a'], r_root);
        }
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node* r = buildTrie(words);
        vector<string> ans;
        int n = board.size();
        if(!n) return ans;
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ch = board[i][j]-'a';
                if(r->child[ch] && r->child[ch]->cnt > 0){
                    dfs(i,j,board,ans,r->child[ch], r);
                }

            }
        }
        return ans;

    }
};
