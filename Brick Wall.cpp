class Solution {
public:
    struct cmp {
       bool operator()(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
           return (a.first>b.first);
       }
    };

    int leastBricks(vector<vector<int>>& wall) {
       priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, cmp> qu;
        int n = wall.size();
        if(n==0) return 0;
        int sum=0;
        for(int i=0;i<wall[0].size();i++){
            sum += wall[0][i];
        }
        for(int i=0;i<n;i++){
            qu.push(make_pair(wall[i][0], make_pair(i,0)));
        }
        int ans = n;
        vector<pair<int,pair<int,int>>> nextItems;
        while(!qu.empty() && qu.top().first < sum){
            int cur= qu.top().first;
            nextItems.clear();
            while(!qu.empty() && qu.top().first == cur){
                nextItems.push_back(qu.top());
                qu.pop();
            }

            ans = min(ans, (int)(n-nextItems.size()));

            for(int i=0;i<nextItems.size() && nextItems[i].first < sum;i++){

                qu.push(make_pair(nextItems[i].first + wall[nextItems[i].second.first][nextItems[i].second.second+1],make_pair(nextItems[i].second.first, nextItems[i].second.second+1)));
            }

        }

        return ans;
    }
};
