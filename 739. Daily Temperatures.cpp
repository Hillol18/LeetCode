/*
             |
 73,74,75,71,69,70,76,73
  
  
 69 70 73 76
  
 73 74 75 76 73 
  
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        vector<int> ans(n, 0);
        
        n--;
        
        stack<int> st;
        while(n >= 0){
            while(!st.empty() && temperatures[st.top()] <= temperatures[n]){
                st.pop();
            }
            
            if(!st.empty()) ans[n] = st.top() - n;
            
            st.push(n);
            n--;
        }
        return ans;
    }
};