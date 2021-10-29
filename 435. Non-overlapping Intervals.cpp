
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        
        int cover = intervals[0][0] - 1;
        int cnt = 0;
        for(int i=0; i<n; i++){
            
            if(intervals[i][0] < cover){
                cnt++;
                
                cover = min(intervals[i][1], cover);
            }
            else {
                cover = intervals[i][1];
            }
        }
        return cnt;
    }
};