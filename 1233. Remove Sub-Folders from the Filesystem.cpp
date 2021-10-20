class Solution {
public:
    
    vector<string> getFolder(vector<string>& folder){
        sort(folder.begin(), folder.end());
        
        int i=0, j=1;
        
        int n = folder.size();
        vector<string> ans;
        ans.push_back(folder[i]);
        while( j < n){
            if(i==j){

                j++;
                continue;
            }
            
            if(folder[j].find(folder[i] + '/') != -1){
                j++;
            }
            else{
                ans.push_back(folder[j]);
                i=j;
            }
        }
        return ans;
    }
    
    struct node{
        bool isEnd;
        string word;
        unordered_map<string, node*> mp;
        node(){
            isEnd = false;
        }
    };
    
    void insertIntoTrie(node *root, string directory){
        string word = directory;
        for(auto &it: directory) {
            if(it == '/') it = ' ';
        }
        
        string token;
        stringstream ss(directory);
        
        while(ss >> token){
            if(root->mp.find(token) != root->mp.end()){
              root= root->mp[token];  
            }
            else{
                root->mp[token] =  new node();
                root = root->mp[token];
            }
        }
        
        root->isEnd = true;
        root->word = word;
    }
    
    void dfs(node *r, vector<string> &ans){
        
        if(r->isEnd == true) {
            ans.push_back(r->word);
            return;
        }
        
        auto it = r->mp.begin();
        while(it != r->mp.end()){
            
            dfs(it->second, ans);
            it++;
        }
    }
    
    vector<string> solve(vector<string>& folder){
        node *r = new node();
        vector<string> ans;
        for(string it: folder){
            insertIntoTrie(r, it);
        }
        dfs(r, ans);
        return ans;
    }
    
    
    vector<string> removeSubfolders(vector<string>& folder) {
        
        return solve(folder);
    }
};