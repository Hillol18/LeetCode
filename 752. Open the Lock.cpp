class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> qu;
        
        qu.push("0000");
        vector<int>visit(10000);
        int cnt = 0;
        for(auto it: deadends){
            visit[stoi(it)] = 1;
        }
    
        if(visit[0]) return -1;
        if(target ==  "0000") return 0;
        visit[0] = 1;
    
        while(!qu.empty()){
            
            int sz = qu.size();
            cnt++;
            while(sz--){
                
                string temp = qu.front();
                qu.pop();
                
                //cout<<temp<<endl;
                for(int i=0;i<4;i++){
                    char c = temp[i];
                    if(temp[i] == '0'){
                        temp[i] = '9';
                    }
                    else{
                        temp[i]--;
                    }
                    
                    if(!visit[stoi(temp)]){
                        qu.push(temp);    
                        visit[stoi(temp)] = true;
                        if(temp == target) return cnt;
                    }
                    
                    temp[i] = c;
                    
                    if(temp[i] == '9'){
                        temp[i] = '0';
                    }
                    else{
                        temp[i]++;
                    }
                    
                    if(!visit[stoi(temp)]){
                        if(temp == target) return cnt;
                        qu.push(temp);    
                        visit[stoi(temp)] = true;
                    }
                    
                     temp[i] = c;
                } 
                
                
                
            }
        }
        return -1;
    }
};