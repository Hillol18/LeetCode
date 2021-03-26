class Solution {
public:

    void help(int pos, string temp, string &data,vector<vector<char>> &path, vector<string> &ans){
        if(pos==data.size()) {
            if(temp.size())
            ans.push_back(temp);
            return;
        }

        int idx = data[pos]-'0';

        for(int i=0;i<path[idx].size();i++){
            help(pos+1, temp + path[idx][i], data,path, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        vector<vector<char>> path(10);
        int idx = 2;
        for(int i=0;i<26;i++){
            path[idx].push_back(i+'a');

            int sz = path[idx].size();

            if(idx==7 || idx ==9){
                if(sz == 4){
                    idx++;

                }
            }
            else if(sz==3) idx++;
        }

        help(0, "", digits, path, ans);

        return ans;
