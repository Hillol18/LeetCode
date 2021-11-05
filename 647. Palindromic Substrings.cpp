/*

| |
aaa
0 2
01
  00
  11
12
 11
 22 
 
 


*/

class Solution {
public:
    int dfs(int i, int j, string &s, vector<vector<int>> &dp){
        if(i==j) return 1;
        int &ret = dp[i][j];
        
        if(ret != -1) return ret;
        ret = 0;
        if(s[i] == s[j]) 
        ret += dfs(i+1, j-1, s, dp);
        
        ret += dfs(i+1, j, s, dp);
        ret += dfs(i, j-1, s, dp);
        //ret -= dfs(i+1, j-1, s, dp);
        
        return ret;
    }
    
    int countPalinDrom(int i, int j, string s){
        int cnt = 0;
        while(i>=0 && j<s.size() && s[i] == s[j]){
            i--;
            j++;
            cnt++;
        }
        return cnt;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans += countPalinDrom(i, i, s);
            ans += countPalinDrom(i, i+1, s);
        }
        //if(n==0) return 0;
        
        //vector<vector<int>> dp(n, vector<int> (n, -1));
        
        //return dfs(0, n-1, s, dp);
        return ans;
        
    }
};