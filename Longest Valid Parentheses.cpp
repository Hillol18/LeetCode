class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(0);
            else if(s[i]==')'){
                if(!st.empty()){
                    int sum = 0;
                    while(!st.empty() && st.top()!=0){
                        sum+=st.top();
                        st.pop();
                    }

                    if(!st.empty()){
                        st.pop();
                        sum++;
                        st.push(sum);
                    }
                    ans= max(ans, sum);
                }
            }
        }


        int temp =0 ;
        while(!st.empty()){
            int cur = st.top();
            if(cur != 0) temp+=cur;
            else temp = 0;
            st.pop();

            ans=max(ans,temp);

        }

        return ans*2;
    }
};
