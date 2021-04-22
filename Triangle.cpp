class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size();
        if(n==0) return 0;
        for(int i=1;i<n;i++){
           for(int j=0;j<triangle[i].size();j++){
               int left = INT_MAX, up=INT_MAX;
               if(j!=0) left =  triangle[i-1][j-1];
               if(j<triangle[i-1].size()){
                   up=triangle[i-1][j];
               }

               triangle[i][j]+= min(up,left);

           }
       }
        int ans = INT_MAX;
       for(int i=0;i<triangle[n-1].size();i++){
           ans = min(ans, triangle[n-1][i]);
       }
        return ans;
    }
};
