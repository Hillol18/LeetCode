class Solution {

public:
    bool isVowel(char c){
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c=='o' || c == 'u') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int cnt1=0,cnt2=0;

        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                if(i<(n/2)){
                    cnt1++;
                }
                else cnt2++;
            }
        }
        return cnt1 == cnt2;
    }
};
