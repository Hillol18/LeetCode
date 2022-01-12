/*
2
  3
4
    5
6 6
      7
8  
  9
10  10
         11
12 12
14    14


*/
class Solution {
public:
    
    vector<int> getPrime(int val){
        int m = val;
        int n = sqrt(m);
        vector<int> mp(m+1);
        vector<int> ans;
        int dif = 1;
        for(int i = 2; i<=m; i+= dif){
            if(i == 3) dif++;
            if(mp[i] == 0){
                ans.push_back(i);
                if(i >=n) continue;
                for(int j = i*i; j<=m; j+=(i+i)){
                    mp[j] = 1;
                }
            }
        }
        return ans;
    }
    
    
    
    int getParent(int value, unordered_map<int, int> &mp){
        if(mp[value] == value) return value;
        return getParent(mp[value], mp);
    }
    
    int setParent(int value, int parent,unordered_map<int, int> &mp){
        if(mp[value] == value){
            mp[value] = parent; 
            return parent;
        }
        return mp[value] = setParent(mp[value],parent, mp);
    }
    
    
    int largestComponentSize(vector<int>& nums) {
              
        int n = nums.size();
        int maxValue = 0;
        for(int i = 0; i<n; i++){
            maxValue = max(maxValue, nums[i]);
        }
        vector<int>prime = getPrime(maxValue + 1);
        
        unordered_map<int, int> mp, group;

        for(int i = 0; i<prime.size(); i++){
            mp[prime[i]] = prime[i];
            group[prime[i]] = 0;
        }
        
        
        int ans = 0;

        for(int i = 0; i<n; i++){
            int val = nums[i];
            int parent = -1;
            int cnt = 0;

            for(int j = 0; j<prime.size() && val >= (prime[j]*prime[j]); j++){
                
                bool isDevisible = false;
                while(val % prime[j] == 0 && val >= prime[j]){
                    val /= prime[j];
                    isDevisible = true;    
                }
                
                if(isDevisible){                  
                    if(parent == -1){
                        parent = getParent(prime[j], mp);
                    }
                    else{
                        int pr = getParent(prime[j], mp);
                        cnt += group[pr];
                        group[pr] = 0;
                        setParent(pr, parent, mp);                        
                    }
                }
            }
            
            if(val > 1){
                    if(parent == -1){
                        parent = getParent(val, mp);
                    }
                    else{
                        int pr = getParent(val, mp);
                        cnt += group[pr];
                        group[pr] = 0;
                        setParent(pr, parent, mp);                        
                    }
            }
            
            cnt++;
            group[parent] += cnt;
            
            ans = max(ans, group[parent]);
        }
        
        return ans;
    }
};