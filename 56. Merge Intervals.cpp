class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if(!n)
            return ans;
        sort(intervals.begin(), intervals.end());
        int low= -1, high = -1;
        for(int i=0;i<n;i++){
            if(low==-1){
                low=intervals[i][0];
                high=intervals[i][1];
            }
            else if(low<= intervals[i][0] && intervals[i][0]<=high){
                high = max(intervals[i][1], high);
            }
            else{
                ans.push_back({low, high});
                low= intervals[i][0];
                high=intervals[i][1];
            }
        }

        ans.push_back({low, high});
       return ans;
    }
};
