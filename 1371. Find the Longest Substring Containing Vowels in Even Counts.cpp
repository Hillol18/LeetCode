class Solution {
public:
    
    int getVowelIdx(char c){
        return string("aeiou").find(c);
    }
    
    int findTheLongestSubstring(string s) {
        int n = s.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int cur = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int idx = getVowelIdx(s[i]);
            if(idx!=-1){
                cur ^= (1<<idx);
            }
            
            if(mp.find(cur) != mp.end()){
                ans = max(ans, i - mp[cur]);
            }
            else{
                mp[cur] = i;
            }
        
            
        }
        
        return ans;
    }
};