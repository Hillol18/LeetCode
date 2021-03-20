class Solution {
public:

    bool isLetter(char c){
        return (('a' <= c && c<= 'z'));
    }

    bool isEnd(string &data, int &index){
        return (index == data.size() || !isLetter(data[index]));
    }

    bool isUpCase(char c){
       return ('A' <= c && c<= 'Z');
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {

        unordered_set<string> u_st;
        unordered_map<string, int> u_mp;

        int n = paragraph.size();


        string temp = "";
        string ans = "";
        int mx = 0;
        for(int i=0;i<banned.size();i++){
            u_st.insert(banned[i]);
        }

        for(int i=0;i<=n;i++){
             if(i<n && isUpCase(paragraph[i])){
                 paragraph[i] = paragraph[i]-'A'+'a';
             }

            if(isEnd(paragraph, i)){

                if(temp.size() && u_st.find(temp) == u_st.end()){
                    u_mp[temp]++;
                    int cnt = u_mp[temp];

                    if(mx<cnt){
                        mx=cnt;
                        ans=temp;
                    }

                }
                temp ="";
            }
            else {
                temp += paragraph[i];
            }
        }

        return ans;
    }
};
