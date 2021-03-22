class Solution {
public:
    unordered_set<string> u_st;
    unordered_map<string,string> u_mp;

    bool isUpCase(char c){
        return ('A' <= c && c<='Z');
    }

    bool isLowCase(char c){
        return ('a' <= c && c<='c');
    }

    bool isVowel(char c){
        c = tolower(c);
        if(c=='a' || c=='e' || c == 'i' || c=='o' || c=='u') return true;
        return false;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = wordlist.size();
        for(int i=0;i<n;i++){
            u_st.insert(wordlist[i]);
            string temp = wordlist[i];
           for(int j=0;j<temp.size();j++){
               temp[j] = tolower(temp[j]);
           }

            if(u_mp.find(temp) == u_mp.end()){
                    u_mp[temp] = wordlist[i];
            }

            for(int j=0;j<temp.size();j++){
                if(isVowel(temp[j])){
                  temp[j]='*';
                }
            }

            if(u_mp.find(temp) == u_mp.end()){
                    u_mp[temp] = wordlist[i];
            }
        }

        int m = queries.size();
        vector<string> ans(m, "");

        for(int i=0;i<m;i++){
          string temp = queries[i];
            if(u_st.find(temp) != u_st.end()){
                ans[i]=temp;
            }
            else{
                for(int j=0;j<temp.size();j++){
                    temp[j]=tolower(temp[j]);
                }

                if(u_mp.find(temp) != u_mp.end()){
                   ans[i] = u_mp[temp];
                }
                else{
                    for(int j=0;j<temp.size();j++){
                        temp[j]=(isVowel(temp[j])?'*':temp[j]);
                    }
                    if(u_mp.find(temp) != u_mp.end()){
                        ans[i] = u_mp[temp];
                    }
                }

            }
        }
        return ans;
    }
};
