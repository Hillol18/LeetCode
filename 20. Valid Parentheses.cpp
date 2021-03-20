class Solution {
public:

    bool isCloseBrac(char c){
        if(c ==')') return true;
        if(c == '}') return true;
        if(c == ']') return true;
        return false;
    }

    char getOpenBrac(char c){
        if(c ==')') return '(';
        if(c == '}') return '{';

        return '[';

    }

    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(isCloseBrac(s[i])){
                if(st.empty() || st.top() != getOpenBrac(s[i]) ) return false;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};
