class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>> ans;
        while(i<n && j<m){
                        //cout<<i<<" "<<j<<endl;
            int p1 = -1, p2 = -1;
            if((firstList[i][0] <= secondList[j][0] && secondList[j][0] <= firstList[i][1])
              || (secondList[j][0] <= firstList[i][0] && firstList[i][0] <= secondList[j][1])){
                p1 = max(secondList[j][0], firstList[i][0]);
                p2 = min(secondList[j][1], firstList[i][1]);
                
                ans.push_back({p1, p2});
                if(p2 == secondList[j][1]) j++;
                else i++;
            }
            else{
                if(secondList[j][1] > firstList[i][1])
                    i++;
                else j++;
            }

        }
        
        return ans;
    }
};