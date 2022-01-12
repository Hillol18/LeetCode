class Solution {
public:
    
    bool isPalindrom(int i, int j, string &s, vector<vector<int>> &dp){
        
        if(dp[i][j] != -1) return dp[i][j];
        int ii = i, jj =  j;
        while(i <= j && s[i] == s[j]){
            i++;
            j--;
        }
        return dp[ii][jj] = (i>j);
    }
    void dfs(int pos, string &s, vector<string>&path, vector<vector<string>> &ans, vector<vector<int>> &dp){
        if(pos == s.size()){
            ans.push_back(path);
            return;
        }
        
        for(int i = pos; i< s.size(); i++){
            if(isPalindrom(pos, i, s, dp)){
                //cout<<"try"<<endl;
                string p = s.substr(pos,i - pos +1);
                path.push_back(p);
                dfs(i+1, s, path, ans, dp);
                path.pop_back();
            }
        }
        
        
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<string>> ans;
        vector<string> path;
        dfs(0, s, path, ans, dp);
        return ans;
        
    }
};