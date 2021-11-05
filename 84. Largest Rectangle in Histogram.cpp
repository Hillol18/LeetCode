/*

1 3 5 6 7



*/

class Solution {
public:
    
    vector<int> getLen(vector<int>& heights, int move){
        int n = heights.size();
        stack<int> st;
        
        int boundary = move == -1 ? n : -1; 
        st.push(boundary);
        vector<int> ans(n, 1);
        int l = 0, r = n-1;
        while(l <= r){
            int &idx = (move == 1 ? l : r );
            
            while(st.top() != boundary && heights[st.top()] >= heights[idx]){
                  st.pop();
            }
        
            ans[idx] = st.top();
            st.push(idx);
            idx += move;
        }
        
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        int ans = 0;
        
        vector<int> left = getLen(heights, 1);
        
        vector<int> right = getLen(heights, -1);
        
        for(int i = 0; i < n; i++){
            ans = max(ans, ((right[i] - left[i] -1) * heights[i]));  
        }
        
        return ans;
    }
};