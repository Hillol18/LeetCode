class Solution {
public:

    int mctFromLeafValues(vector<int>& arr) {

        int ans = 0;
        int len = arr.size();
        stack<int> st;
        for(int i=0;i<len;i++){
            while(!st.empty() && st.top() < arr[i]){
                int pre=st.top();
                int cur = st.top()*arr[i];
                st.pop();

                if(!st.empty()){
                    cur = min(cur, st.top() * pre);
                }

                ans+= cur;
            }
            st.push(arr[i]);
        }

        while(!st.empty() && st.size() >1){
            int x = st.top();
            st.pop();
            int y = st.top();
            ans+=x*y;
        }

        return ans;

    }
};
