class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int n = points.size();
        int safe = 0;
        vector<double> slope;
        for( int i=0; i<n; i++){
            double deg = 0;
            if(points[i][0] == location[0] && points[i][1] == location[1]){
                safe++;
                continue;
            }
            
            deg = atan2((points[i][1]-location[1]), (points[i][0]- location[0])) * 180.00 / (acos(0.0)*2.0);
            if(deg < 0) deg += 360.00;
            slope.push_back(deg);
        }
        
        sort(slope.begin(), slope.end());

        int low = 0, high = 0;
        int flag = 3;
        
        int cnt = 1;
        int ans = 0;
        
        n-=safe;
        vector<int> visit(n,0);
        while(flag && n){
            if(high == 0){
                flag --;
            }
            
            bool flag = true;

            while(cnt > 0 && flag){
                
                double lowDeg = slope[low];
                double highDeg = slope[high];
                if(visit[high]){
                    highDeg = 360.00 + highDeg;
                    
                }

                if(((highDeg - lowDeg) - (double)angle) <= 0.00) {
                    break;
                }; 
                
                low++;
                low %= n;
                cnt--;
            }
            
            ans = max(ans, cnt);
            visit[high] = 1;
            cnt++;
            high++;
            high %= n;
        }
        
        return ans+safe;
    }
};