class WordFilter {
public:

    struct trie{
        trie *node[27];
        int ans=-1;
        trie(){
            for(int i=0;i<27;i++) node[i]=NULL;
        }
    };

    trie *tr = NULL;

    int findIndex(char c){
        int idx = 26;
        if('a' <= c && c <= 'z'){
            idx = c - 'a';
        }
        return idx;
    }
    void insertIntoTrie(trie *root, string word, int index){
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            int idx = findIndex(word[i]);
            if(!root->node[idx])
            root->node[idx] = new trie();
            root= root->node[idx];
            root->ans = index;
        }

    }

    void process(string word, int index, trie *root){
        int n = word.size();
        string suffix = "";
        insertIntoTrie(root, "#"+word, index);
        string temp;
        for(int i=n-1;i>=0;i--){
            suffix = word[i] + suffix;
            temp = suffix+"#"+word;
            //cout<<temp<<endl;
            insertIntoTrie(root, temp, index);
        }
    }

    void dfs(trie *r, string word){
        int flag = 0;
        //cout<<string(1, 'b')<<endl;
        for(int i=0;i<26;i++){
            if(r->node[i]){
                flag=1;
                dfs(r->node[i], word + string(1,'a' + i));
            }
        }

        if(r->node[26]){
            flag=1;
            dfs(r->node[26], word + "#");
        }

        if(!flag) cout<<word<<" +"<<endl;
    }


    int search(trie *r, string w){
        int ans =-1;
        int i=0;
        for( i=0;i<w.size()&& w.size()>1 && r;i++){
           r = r->node[findIndex(w[i])];
           if(r) ans = r->ans;
        }
        if(i!=w.size()) ans = -1;
        return ans;
    }

    WordFilter(vector<string>& words) {
        trie *t = new trie();
        tr = t;

        for(int i=0;i<words.size();i++){
            process(words[i], i, t);
        }
    }

    int f(string prefix, string suffix) {
       return search(tr, suffix+ "#"+ prefix);
    }
};
