/*

[[6,5],[13,2],[17,1],[19,2],[20,5]]

|
6 13 17 19 20
5 2  1  2  5

17 13
1   2

3x - 4 = 2x - 7

*/

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
       stack<vector<double>> st;
        int n = cars.size();
        double frac = 0.000000001;
        vector<double> ans(n);
        
        int sz = cars.size();        
        
        reverse(cars.begin(), cars.end());
        for(auto it: cars){
            bool flag = true;
            
            while(!st.empty() && flag){
                if(st.top()[1] < it[1]){
                    flag = false;
                    auto tt = st.top();
                    st.pop();
                    double time = (tt[0] - double(it[0])) / (double(it[1])-tt[1]);

                    if(!st.empty() && (st.top()[0] + time* st.top()[1]) < (tt[0] + time * tt[1])){
                        flag = true;
                    }
                    else{
                        st.push(tt);    
                    }      
                }
                else{
                    st.pop();    
                }
            }
            
            if(st.empty()){
                ans[--sz] = -1.00;
            }
            else{
                auto top = st.top();
                double time = (top[0] - double(it[0])) / (double(it[1])-top[1] );
                ans[--sz] = time;
            }
            
            st.push({ double(it[0]), double(it[1])});
        }
        return ans;
    }
};