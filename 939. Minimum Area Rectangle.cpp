class Solution {
public:
    
   
    
    
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> st;     
        //st.insert(make_pair(0, 0));
        for(auto it: points){
            st[it[0]].insert(it[1]);
        }
        
        int n = points.size();
        int x,y;
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                x = points[i][0];
                y = points[j][1];
                
                if(points[i][0] == points[j][0] || points[i][1] == points[j][1]) continue;
                
                bool firstPoint = false, secondPoint = false;
                
                if(st.find(x) != st.end() && st[x].find(y) != st[x].end()){
                    firstPoint = true;
                }
                
                x = points[j][0];
                y = points[i][1];
                
                if(firstPoint && st.find(x) != st.end() && st[x].find(y) != st[x].end()){
                    secondPoint = true;
                }
                
                if(secondPoint && firstPoint){
                    //cout<<points[i][0] - points[j][0]<<" "<<points[i][1] - points[i][1]<<endl;
                    ans = min(ans, abs(points[i][0] - points[j][0])* abs(points[i][1] - points[j][1]));
                }
                
            }
        }
        
        return ans == INT_MAX? 0 : ans;
        
    }
};