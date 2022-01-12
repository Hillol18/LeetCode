/*
                      |
    012345678910 11 12
    (()()(()() ( )  ))))
    5
    
    
    12
    
    
    
    ((  
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            
            if(s[i]==')' && !st.empty() && s[st.top()] == '('){
                st.pop();    
            }
            else st.push(i);
            
        }
        
        int len = s.size();

        while(!st.empty()){
            ans = max(ans, len - st.top() -1);
            len = st.top();
            st.pop();
        }
        
        ans = max(ans, len);        
        return ans;
    }
};