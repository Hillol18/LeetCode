class Solution {
public:
    void dfs(int pos, int br, string &s, string path, unordered_set<string> &ans, int cnt){
        if(pos == s.size()){
            if(!br && !cnt) ans.insert(path);
            return ;
        } 
        
        if(br<0) return ;
        
        if(s[pos] == '(' || s[pos] == ')'){
            if(s[pos] == '('){
                dfs(pos+1, br + 1, s, path + "(", ans, cnt);   
            }
            else if(s[pos] == ')'){
                dfs(pos+1, br - 1, s, path + ")", ans, cnt);
            }
            dfs(pos+1, br, s, path, ans, cnt-1);
        }
        else
         dfs(pos+1, br, s, path + s[pos], ans, cnt);
        
    }
    vector<string> removeInvalidParentheses(string s) {
        
        int cnt = 0;
        int rmCnt = 0;
        for(char c: s){
            if(c==')'){
                cnt -= 1;
            }
            else if(c == '('){
                cnt += 1;
            }
            
            if(cnt<0){
                rmCnt ++;
                cnt = 0;
            }
        }
        rmCnt += cnt;
        cout<<rmCnt<<endl;
        unordered_set<string> ans;
        dfs(0, 0, s, "", ans, rmCnt);
        vector<string>d;
        auto it = ans.begin();
        while(it != ans.end()){
            d.push_back(*it);
            it++;
        }
        return d;
    }
};