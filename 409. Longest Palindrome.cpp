class Solution {
public:
    int getPalindromLength(int i, int j, string &s){
        int n = s.size();
        while(i>=0 && j<n && s[i] == s[j]){
            i--;
            j++;
        }
        
        return j-i-1;
    }
    
    int getIndex(char c){
       if('a' <= c && c <= 'z') return c-'a';
       if('A' <= c && c <= 'Z') return c-'A' + 26; 
        return 0;
    }
    
    int longestPalindrome(string s) {
        int n = s.size();
        int mx = 0;
        long long int bit = 0;
        for(int i = 0; i<n; i++){
           bit ^= (1LL << getIndex(s[i]));
        }
        int cnt = 0;
        for(int i = 0; i<53; i++){
            if(bit & (1LL<<i)) cnt++;
        }
        if(cnt > 1) n = n - cnt + 1;
        return n;
    }
};