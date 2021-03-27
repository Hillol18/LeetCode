class Solution {
public:

    struct cmp{
        bool operator()(vector<int> &a, vector<int> &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]>b[0];
        }
    };

    int minMeetingRooms(vector<vector<int>>& intervals) {
        multiset<pair<int,int>> st;
        priority_queue<vector<int>, vector<vector<int>>, cmp> qu;
        for(int i=0;i<intervals.size();i++){
            qu.push({intervals[i][0], 1});
            qu.push({intervals[i][1], -1});
        }

        int sum=0;
        int ans= 0;
        while(!qu.empty()){
            //cout<<qu.top()[0]<<" "<<qu.top()[1]<<endl;
            sum+=qu.top()[1];

            ans = max(ans, abs(sum));
            qu.pop();
        }
        return ans;
    }
