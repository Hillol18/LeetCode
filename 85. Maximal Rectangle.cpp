class Solution {
public:
    
    vector<int> getMaxLen(vector<int> &data, int move){
        int n = data.size();
        int boundary = move == -1 ? n : -1;
        stack<int> st;
        vector<int> ans(n);
        st.push(boundary);
        
        int l = 0, r = n-1;
        while(l <=  r){    
            int &idx = move == -1 ? r : l;
            
            while(st.top() !=  boundary && data[st.top()] >= data[idx]){
                st.pop();
            }
            
            ans[idx] = st.top();
            st.push(idx);
            
            idx += move;
         }
        
        return ans;
    }
    
    int getArea(vector<int> data){
        int n = data.size();
       
        vector<int> left = getMaxLen(data, 1);
        vector<int> right = getMaxLen(data, -1);
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, (right[i] - left[i] - 1) * data[i]);
        }
        return ans;
    }
    
    int getArea2(vector<int> data){
        data.push_back(0);
        int n = data.size();
        
        stack<pair<int, int>> st;
        
        st.push(make_pair(0, -1));
        int ans = 0;
        for(int i = 0; i<data.size(); i++){                
            while(!st.empty() && st.top().first > data[i]){
                int h = st.top().first;
                st.pop();
                int sz = i - st.top().second - 1;
                ans = max(ans, h * sz);                   
            }
            st.push(make_pair(data[i], i));
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n =  matrix.size();
         if(n == 0 ) return 0;
        int m = matrix[0].size();
        vector<int> data(m, 0);
        int ans = 0;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '1') data[j] += 1;
                else data[j] = 0;
            }
           
            ans = max(ans, getArea2(data));
        }
        
        return ans;
    }
};