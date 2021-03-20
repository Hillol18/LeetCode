class Solution {
public:

    stack<int> st;

    int calc(stack<int> &st, int h, vector<int> &data){

        int sum = 0;
        int x = data[st.top()];
          while(!st.empty() && data[st.top()] ==x) st.pop();

        if(!st.empty()){
            sum += (min(data[st.top()], data[h]) - x) * (h-st.top()-1);
        }

        return sum;
    }

    int trap(vector<int>& height) {
        int n = height.size();

        int sum = 0;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()] < height[i] ){
                sum+=calc(st, i, height);
            }
            st.push(i);
        }

        return sum;
    }
};
