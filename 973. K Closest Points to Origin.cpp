class Solution {
public:

    struct cmp{
        bool operator()(pair<int, int> &a, pair<int,int> &b){
           return a.first < b.first;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, int>, vector<pair<int,int>>> qu;
        int n = points.size();
        for(int i=0;i<n;i++){
            qu.push(make_pair(points[i][0]*points[i][0] + points[i][1]* points[i][1], i));
            if(qu.size()>k){
                qu.pop();
            }
        }

        vector<vector<int>> ans;
        while(!qu.empty()){
            ans.push_back(points[qu.top().second]);
            //cout<<qu.top().first<<endl;
            qu.pop();
        }
        return ans;
    }
};
