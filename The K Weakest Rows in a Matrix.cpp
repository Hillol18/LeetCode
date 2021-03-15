class Solution {
public:
    struct cmp {
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            if(a.first == b.first){
                return a.second <b.second;
            }

            return a.first < b.first;
        }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp>qu;

        vector<int> ans;
        int n = mat.size();
        if(n==0) return ans;
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) cnt++;
                else break;
            }

            qu.push(make_pair(cnt, i));

            if(qu.size()>k) qu.pop();
        }

        while(!qu.empty()){
            ans.push_back(qu.top().second);
            qu.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
