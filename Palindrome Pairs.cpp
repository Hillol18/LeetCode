class Solution {
public:
    
    struct node {
        node(){
            index = -1;
            ch = vector<node*>(26);
        }
        
        vector<node*> ch;
        int index;
    };
    
    void insertIntoTrie(string w, int index, node *r){
        reverse(w.begin(), w.end());
        for(int i=0;i<w.size();i++){
            if(!r->ch[w[i]-'a'])
            r->ch[w[i]-'a'] = new node();
            r = r->ch[w[i]-'a'];
        }
        
        r->index = index;
    }
    
    
    bool isPalindrom(string w){
        int i = 0, j = w.size();
        j--;
        while(i<=j){
            if(w[i] != w[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void dfs(node *r,int idx, string w, int index, string ex, vector<vector<int>> &ans){
        
        int low = 0, high = 25;
        
        if(r->index != -1 && r->index !=  index){
            if(idx == w.size() && isPalindrom(ex)){
                    ans.push_back({index, r->index});
            }
            else if(idx < w.size()){
                string temp = w.substr(idx);
                if(isPalindrom(temp)){
                    ans.push_back({index, r->index});
                }
            }
        }
        
        if(idx < w.size()) low = high = (w[idx]-'a');
        
        
        for(int i= low; i <= high; i++){
            if(r->ch[i]){
                
                dfs(r->ch[i], idx + (idx != w.size()), w, index, ex + (idx == w.size() ? string(1,(i+'a')) : "") , ans);    
            }
            
        }
        
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        node *r = new node();
        for(int i = 0; i< words.size(); i++){
           insertIntoTrie( words[i], i, r );
        }
        
        vector<vector<int>> ans;
        
        //dfs(r, 0, "", 0, "", ans);   
        for(int i = 0; i< words.size(); i++){
            dfs(r, 0, words[i], i, "", ans);   
        }
        return ans;
    }
};