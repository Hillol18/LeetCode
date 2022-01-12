class Solution {
public:
    
    vector<int> populateFailureTable(string s){
        int n = s.size();
        vector<int> failure(n, 0);
        
        int i = 0;
        int j = 1;
        while(j < n){
            if(s[j] == s[i]){
                i++;
                failure[j] = i;
                j++;
            }
            else if(i > 0){
               i = failure[i-1];
            }
            else{
                j++;
            }
        } 
        
        return failure;
    }
    
    string removeOccurrences(string s, string part) {
    
        vector<int> failure = populateFailureTable(part);
        
        stack<pair<char, int>> st;
        
        int n = s.size();
        
        int j = 0;
        for(int i = 0; i < n; i++){
                     
            while(j > 0 && part[j] != s[i]){
               j = failure[j-1]; 
            }
            
            if(part[j] == s[i]){
                j++;
            }
            
            if(j == part.size()){
                j--;
                while(j){
                    j--;
                    st.pop();
                }
                
                if(!st.empty()){
                    j = st.top().second;
                }
            }
            else{
                st.push(make_pair(s[i], j));
            }
            
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top().first;
            st.pop();
        }
        int i = 0;
        j= ans.size()-1;
        while(i < j){
            swap(ans[i], ans[j]);
            i++;
            j--;
        }
        
        return ans;

    }
};