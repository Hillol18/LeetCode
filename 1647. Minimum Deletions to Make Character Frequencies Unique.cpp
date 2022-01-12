class Solution {
public:
    int minDeletions(string s) {
        vector<int>mp(26, 0);
        
        for(int i= 0; i<s.size(); i++){
            mp[s[i] - 'a']++;
        }
        
        sort(mp.begin(), mp.end());
        
        int level = mp[25];
        int i = 25;
        int ans = 0;
        while(i >=0 && mp[i] > 0){
            //cout<<mp[i]<<" "<<level<<endl;
            if(mp[i] >= level || level == 0){
                ans += (mp[i] - level);
            } 
            if(level != 0)
            level = min(mp[i], level) - 1;
            i--;
        }
        return ans;
    }
};