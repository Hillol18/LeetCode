/*
   
*/

class Solution {
public:
    long long int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    
    long long int& getInt(char x){
        if(x < 64) return x1;
        if(x < 128) return x2;
        if(x < 192) return x3;
        return x4;
    }
    
    int lengthOfLongestSubstring(string s) {
        
        int i, j;
        i = j = 0;
        int n = s.size();
        int ans = 0;
        
        while(j < n){
            long long int &mp_j = getInt(s[j]);
            int idx = s[j] % 64;

            while(((1LL<<idx) & mp_j)){
                long long int &mp_i = getInt(s[i]);
                int idx_i = s[i] % 64;
                
                mp_i ^= (1LL<<idx_i);
                i++;
            }
            mp_j |= (1LL<<idx);
            ans = max(ans, j-i+1);
            j++;
            
        }
        
        return ans;
    }
};