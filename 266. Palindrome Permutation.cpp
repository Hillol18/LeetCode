/*
Nafiul

00001000
00100000
*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int state = 0;
        int n = s.size();
        for(int i = 0; i<n; i++ ){
            state ^= (1 << (s[i]-'a'));
        }
        
        if((n%2 && (1<<((int)log2(state))) == state) || (n%2 == 0 && state == 0)) return true;
        return false;
    }
};