class Solution {
public:
    int scoreOfParentheses(string S) {
        int len = S.size();
        int sum = 0;
        int cnt=0;
        for(int i=0;i<S.size()-1;i++){
         if(S[i]=='(' && S[i+1]==')'){
           //cnt++;
             sum+=(1<<cnt);
           i++;
         }
         else if(S[i]=='(')
             cnt++;
          else if(S[i] == ')' ) cnt--;
        }
        return sum;
    }
};
