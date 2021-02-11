
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {

        int ans = INT_MIN;
        deque<vector<int>> qu;

        int len = points.size();


        for(int i=0;i<len;i++){


            while(!qu.empty() && (points[i][0] - qu.back()[0]) > k ) qu.pop_back();

            if(!qu.empty()){
                //cout<<qu.front()[1]<<" "<<qu.back()[1]<<endl;
                ans= max(ans, points[i][0] + points[i][1] + qu.back()[1]);
            }
            points[i][1] -= points[i][0];
            while(!qu.empty() && qu.front()[1] < points[i][1] ) qu.pop_front();

            qu.push_front(points[i]);

        }

        return ans;
    }
};
