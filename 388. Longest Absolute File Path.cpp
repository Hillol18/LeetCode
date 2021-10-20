class Solution {
public:
    pair<int, int> getNextWord(int &pos, string input, bool &existDot){
        int cnt = 0;
        while(pos < input.size() && input[pos] == '\t'){
            cnt++;
            pos++;
        }
        

        int len = 0;

        while(pos < input.size() && input[pos] != '\n'){
            
            if(input[pos] == '.') existDot = true;
            len++;
            pos++;
            
        }
        
        if(pos < input.size() && input[pos] == '\n'){
            pos++;
        }
        
        return make_pair(cnt, len);
    }
    
    int lengthLongestPath(string input) {
        int i=0;
        int n = input.size();
        stack<pair<int,int>> st;
        int total = 0;
        int ans = 0;
        bool dot = false;
        while(i < n){
            //cout<<i<<endl;
            dot = false;
           auto it = getNextWord(i, input, dot);
            
            while(!st.empty() && st.top().first >= it.first){
                total -= st.top().second;
                if(total) total--;
                st.pop();
            }
            
            if(total) total++;
            
            total += it.second;
            st.push(it);

            if(dot)
            
            ans = max(ans, total);
        }
        return ans;
    }
};