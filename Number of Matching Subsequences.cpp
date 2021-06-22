class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        int  m = words.size();
        
        vector<vector<int>> pre(26);
        
        for(int i = 0; i < n; i++){
            pre[s[i]-'a'].push_back(i);
        } 
        
        int ans = 0;
        for(int i = 0; i < m; i++){
            int sz = words[i].size();
            int cur = -1, j=0;
            for(j = 0; j < sz; j++){
                //cout<<cur<<" ";
               auto it = upper_bound(pre[words[i][j]-'a'].begin(), pre[words[i][j]-'a'].end(), cur);
                if(it == pre[words[i][j]-'a'].end()) break;
                cur = *it;
                //cout<<cur<<endl;
                
            }
            
            if(j==sz){
                ans++;
                //cout<<i<<endl;
            }
        }
        return ans;
    }
};