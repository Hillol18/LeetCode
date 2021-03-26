class Solution {
public:

    bool help(int i,int j, string &s, string &p, vector<vector<int>> &dp){
        if(i==s.size() && j==p.size()) return true;

        if(i>s.size()) return false;
        if(j>p.size()) return false;

        int &ret = dp[i][j];
        if(ret !=-1)
            return ret;
        ret = 0;
        if(p[j]==s[i]) ret |= help(i+1, j+1, s, p, dp);

        if(ret!=1 && p[j]=='*'){
            ret |= help(i+1, j,s,p,dp);
            ret |= help(i, j+1,s,p,dp);
        }

        if(ret!=1 && p[j]=='?'){
            ret |= help(i+1, j+1,s,p,dp);
        }

        return ret;
    }

/*
    0 1 2 3 4
    a d c e b
*   1 1 1 1 1
a   1 0 0 0 0
?   1 1 0
b   0

*/

    bool iterative(string s, string p){

        vector<int>pre(s.size(), 0);
        vector<int> cur(p.size(),0);

        for(int i=0;i<p.size();i++){

            for(int j=0;j<s.size();j++){

                bool left = true;

                cur[j] = true;

                if((s[j] == p[i]) || (p[i] == '?')){
                    if( j>0 ){
                        cur[j]=cur[j]& pre[j-1];
                    }
                    else if(i>0){
                        cur[j] = pre[j] & cur[j];
                    }
                }

                if(p[j] == '*'){
                    left = true;
                    if(j>0)
                        left=cur[j-1];
                    cur[j] = left;
                }

            }

            pre = cur;
            cur.resize(s.size(),0);
        }
        return pre[s.size()-1];
    }


    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1, vector<int>(p.size()+1,-1));

        return help(0,0,s,p,dp);
    }
};
