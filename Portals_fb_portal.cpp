#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getSecondsRequired(int R, int C, vector<vector<char>> G) {
  // Write your code here
  vector<vector<bool>> visit(R, vector<bool>(C));
  
  vector<vector<vector<int>>> portal(26);
  
  queue<vector<int>> qu;
  vector<int>r { 0, -1, 0, 1};
  vector<int>c {-1,  0, 1, 0};
  
  for( int i=0; i < R; i++){
    for( int j = 0; j < C; j++){
      if(G[i][j] == 'S'){
        qu.push({i,j});
        visit[i][j] = true;
      }
      else if('a' <= G[i][j] && G[i][j] <= 'z'){
        portal[G[i][j] - 'a'].push_back({i, j});
      }
      else if(G[i][j] == '#') visit[i][j] = true;
    }
  }
  
  int cnt = 0;
  vector<int> pVisit(26, -1);
  
  while(!qu.empty()){
    cnt++;
    int sz = qu.size();
  
    for(int i=0; i<26; i++){
      if(pVisit[i] == 1){
        pVisit[i] = 0;
        for(auto it: portal[i]){
          if(visit[it[0]][it[1]]) continue;
          
          visit[it[0]][it[1]] = true;
          qu.push(it);
        }
      }
    }
    
    while(sz--){
      auto cur = qu.front();
      qu.pop();
      
      for(int i=0; i<4; i++){
        int rr = cur[0] + r[i]; 
        int cc = cur[1] + c[i];
        
        if(rr < 0 || cc < 0 || rr >= R || cc >= C ) continue;
        
        if(visit[rr][cc]) continue;
        
        if('a' <= G[rr][cc] && G[rr][cc] <= 'z' && pVisit[G[rr][cc] - 'a'] ==  -1){
          pVisit[G[rr][cc] - 'a'] = 1;
        }
        
        qu.push({rr, cc});
        visit[rr][cc] = true;
        
        if(G[rr][cc] == 'E') return cnt;
      }
      
    }
  }
  
  return -1;
}