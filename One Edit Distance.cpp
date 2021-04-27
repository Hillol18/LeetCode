class Solution {
public:

    void helper(int &i, int &j, string &s, string &t){
        while(i<s.size() && j<t.size() && s[i] == t[j]) {
            i++;
            j++;
        }
    }

    bool isGetResult(int i, int j, string s,string t){
        return (i==s.size() && j== t.size());
    }

    bool isOneEditDistance(string s, string t) {

        //if(!(s.size() || t.size())) return false;

        int i=0, j=0;
        helper(i,j, s,t);
        if(isGetResult(i,j,s,t)) return false;

        //update
        int k=i,l=j;
        helper(++k,++l,s,t);
        if(isGetResult(k,l,s,t)) return true;

        //delete
        k=i,l=j;
        helper(++k,l,s,t);
        if(isGetResult(k,l,s,t)) return true;

        //insert
        k=i,l=j;
        helper(k,++l,s,t);
        if(isGetResult(k,l,s,t)) return true;

        return false;
    }
};
