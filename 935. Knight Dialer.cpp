class Solution {
public:
    int md = 1000000007;
    int dfs(int p, int n, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(n == 0) return 1;
        //cout<<p <<" "<<n<<endl; 
        int &ret = dp[p][n];
        
        if(ret != -1) return ret;
        
        ret = 0;
        
        for(auto it: grid[p]){
           ret += dfs(it, n-1, dp, grid);    
            
            ret %= md;
        }
        
        return ret;
    }
    
    int knightDialer(int n) {
        vector<vector<int>> adj(10);
        cout<<"f"<<endl;
        adj[0] = {4, 6};
        adj[7] = {2, 6};
        adj[8] = {1, 3};
        adj[9] = {2, 4};
        adj[4] = {0, 9, 3};
        adj[6] = {1, 7, 0};
        adj[1] = {6, 8};
        adj[2] = {7, 9};
        adj[3] = {4, 8};
                
        vector<vector<int>> dp(10, vector<int>(n+1, -1));
        int ans = 0;
        for(int i=0;i<=9;i++){
           ans += dfs(i, n-1, dp, adj);
            ans %= md;
        }
        
        return ans;
    } 
};