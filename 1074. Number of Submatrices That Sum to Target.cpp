/*
[[0,1,0]
,[1,1,1]
,[0,0,0]]
    | |
0
*/
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        int n = matrix.size();
        if(n==0) return ans;

        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }

        unordered_map<int,int> mp;

        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                mp.clear();
                mp[0]=1;
                int sum = 0;
                for(int k=0;k<n;k++){
                    int v = matrix[k][j];
                    if(i>0){
                        v-=matrix[k][i-1];
                    }
                    sum+=v;
                    ans += (mp.find(sum-target) != mp.end()) ? mp[sum-target] : 0;

                    mp[sum]++;
                }
            }
        }

        return ans;
    }
};
