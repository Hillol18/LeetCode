class Solution {
public:
     vector<vector<string>> shortestWordEditPath( string& source, string& target, vector<string>& words)
    {

        unordered_set<string>u_st,st;


        int n = words.size();
         for(int i=0;i<n;i++)
             u_st.insert(words[i]);

        vector<vector<string>> ans;
        vector<string>path;

         string s = source;
        queue<vector<string>> qu;

        int step=1;

         if(u_st.find(target) == u_st.end()) return ans;

        if(source == target ) {
           path.push_back(source);
            ans.push_back(path);
         return ans;
        }

        qu.push({s});

         u_st.erase(s);

        bool flag = false;
        while(!qu.empty() && !flag){

        auto it= st.begin();
        int sz= qu.size();
                while(it != st.end()){
                    u_st.erase(*it);
                    it++;
                }
                st.clear();
        step++;
            while(sz--){
                path = qu.front();
                string temp = path.back();
                //cout<<temp<<" "<<step<<endl;
                qu.pop();
                char pre;

                for(int i=0;i<temp.size();i++){
                    pre = temp[i];
                    for(int j=0;j<26;j++){
                        temp[i] = 'a'+j;

                         if(temp == target)
                        {
                            flag=true;
                            path.push_back(target);
                            ans.push_back(path);
                            path.pop_back();

                        }
                         if(u_st.find(temp) != u_st.end()){
                            //cout<<" -- "<<temp<<endl;
                            st.insert(temp);
                            //u_st.erase(temp);
                            path.push_back(temp);
                            qu.push(path);
                            path.pop_back();
                        }
                    }
                    temp[i]=pre;
                }
            }
        }

        return ans;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        return shortestWordEditPath( beginWord, endWord, wordList);
    }
};
