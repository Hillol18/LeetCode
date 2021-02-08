/*
Hillol
*/

/**
An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.

graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

Example 1:

Input: [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:

Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]

**/
class Solution {
public:

    int fun(int pos, int mask, vector<vector<int>> &dp, int &len, vector<vector<int>> &g){
        //cout<<pos<<" "<<mask<<endl;
        if(mask == ((1<<len)-1))
            return 0;
        int &ret = dp[pos][mask];
        if(ret !=-1)
            return ret;
        ret = 100000;
        for(int i=0;i<len;i++){
            if(!(mask & (1<<i)))
              ret = min(ret, g[pos][i] + fun(i,mask|(1<<i), dp, len, g));
        }
        return ret;
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size()+1;

        vector<vector<int>> sp(n+1, vector<int>(n+1, 100000));

        for(int i=0;i<n-1;i++){
            sp[i][i]=0;
            sp[n-1][i] =0;
            for(int j=0;j<graph[i].size();j++){
                if(i != graph[i][j])
                    sp[i][graph[i][j]] = 1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                   sp[i][j] = min(sp[i][j], sp[i][k] + sp[k][j]);
                }
            }
        }

        vector<vector<int>>dp(n+1, vector<int>(1<<n, -1));
        int len = n-1;
        return fun( len, 0, dp, len, sp);

    }
};
