class Solution {
public:
    int shortestWordEditPath( string& source, string& target, vector<string>& words)
    {

        unordered_map<string, int>u_mp;
        int n = words.size();

        for(int i=0;i<n;i++){
            u_mp[words[i]] = i;
        }

        string s = source;
        queue<string> qu;

        vector<int> visit(words.size(),0);
        int step=1;

        if(source == target ) return step;

        qu.push(s);

        if(u_mp.find(s) != u_mp.end()){
            visit[u_mp[s]]=1;
        }

        while(!qu.empty()){

        int sz= qu.size();
        step++;
        while(sz--){
            string temp = qu.front();
            qu.pop();
            char pre;

            for(int i=0;i<temp.size();i++){
            pre = temp[i];
            for(int j=0;j<26;j++){
                temp[i] = 'a'+j;

                if( u_mp.find(temp) != u_mp.end()){
                    if(temp == target) return step;
                    if(visit[u_mp[temp]] == 0){
                        qu.push(temp);
                        visit[u_mp[temp]]=1;
                    }
                }
            }
            temp[i]=pre;
            }
        }
    }

  return 0;
}

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return shortestWordEditPath(beginWord, endWord,wordList);
    }
};
