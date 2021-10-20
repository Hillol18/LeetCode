class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
       auto it = make_pair(price, 1);
       while(!st.empty() && st.top().first <= price){
           it.second += st.top().second;
           st.pop();
       }
        
        st.push(it);
        return it.second;
    }
};