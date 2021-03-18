class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0, j = s.size()-1;

        if(j<0)
            return 0;

        while(i<=j && s[i] ==s[j]){
            i++;
            j--;
        }

       return i<j ? 2: 1;
    }
};
