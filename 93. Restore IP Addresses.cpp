class Solution {
public:

    void dfs(int pos, string &s, vector<string> &ans, string path, int cnt){
       if(pos == s.size()){
           if(cnt==3)
           ans.push_back(path);
           return;
       }
        if(cnt == 3) return;

        string temp="";
        int value = 0;
        if(pos) temp=".";
       for(int i = 0; i < 3 && (pos+i)<s.size() ; i++){
           int idx = (s[pos+i]-'0');
           value *= 10;
           value += idx;
           if((i && value < 10) || value > 255) break;
           temp += s[pos+i];

           dfs(pos+i + 1, s, ans, path + temp, pos != 0 ? cnt + 1 : cnt);
       }

    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(0, s, ans, "", 0);
        return ans;
    }
};
