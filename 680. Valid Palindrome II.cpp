class Solution {
public:
    void travarse(int &i, int &j, string &s){
        while(i<j && s[i] == s[j]){
            i++;
            j--;
        }
    }

    bool validPalindrome(string s) {
        int i=0, j=s.size();
        j--;
        travarse(i,j,s);
        if(j-i <= 0){
            return true;
        }

        int k=i+1,l=j;
        travarse(k,l,s);

        if(l-k <=0) return true;

        k=i,l=j-1;
        travarse(k,l,s);

        if(l-k <=0) return true;
        return false;
    }
};
