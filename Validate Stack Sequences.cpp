
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int m = popped.size();
        int j=0;
        stack<int> st;
        for(int i=0;i<n;i++)  {
             while(!st.empty() && j<m  && st.top() == popped[j]){
                 st.pop();
                 j++;
             }
            st.push(pushed[i]);
        }
        //cout<<j<<endl;

        while(!st.empty() && j<m  && st.top() == popped[j]){
                 st.pop();
                 j++;
             }

        if(j==m)
            return true;
        return false;
    }
};
