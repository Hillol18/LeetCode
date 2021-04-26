
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> qu;
        int sum = 0;
        int n = heights.size();
        int ans = 0;
        for(int i=1;i<n;i++){
            if(heights[i] > heights[i-1]){
                qu.push(heights[i]-heights[i-1]);
                int sz = ladders;
                if(qu.size() > sz){
                    sum+= (int)qu.top();
                    qu.pop();
                    if(sum > bricks) break;
                }
            }

            ans = i;
        }

        return ans;

    }
};
