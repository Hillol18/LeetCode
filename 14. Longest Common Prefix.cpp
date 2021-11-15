class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int j = 0;
        bool flag = true;

        for(j=0; flag; j++){
            for(int i = 0; i<n; i++){
                if(strs[i].size() == j || (strs[i][j] != strs[0][j])){
                    flag = false;
                    break;
                }
            }    
        }
        
        string ans = (j-1 > 0 ? strs[0].substr(0, j-1) : "");
        return ans;
    }
};