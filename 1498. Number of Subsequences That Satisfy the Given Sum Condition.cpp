/*
[3,3,3,3,6,8]
10


      |
3,3,3,3,6,8


1 2 4

  
  
  power()
  SeriesSum()

*/
class Solution {
public:
    
    int md = 1000000007;
    

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<pair<int,int>> power(n+1);
        power[0] = make_pair(1, 1);
        
        for(int i=1; i<=n; i++){
            power[i] = make_pair((power[i-1].first * 2) % md, (power[i-1].second + ((power[i-1].first * 2) % md)) % md);        
        }

        int j = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            
            if(nums[i] > target) continue;
            if((nums[i]*2) <= target) j = i;
            
            while(j >= 0 && (nums[j] + nums[i]) > target) j--;

            if(j >= 0){
                int pwIndex = i-j-1;
                int sumIndex = j;
                if(i==j) sumIndex = 0, pwIndex = j;
                long p = power[pwIndex].first;
                long s = power[sumIndex].second;

                s = (p*s) % md;
                ans += s;
                
                ans %= md;
            }
        }
        return ans;
    }
    
};


/*
[3,3,3,3,6,8]
10


      |
3,3,3,3,6,8


1 2 4

  
  
  power()
  SeriesSum()

*/
class Solution {
public:
    
    int md = 1000000007;
    

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> power(n+1);
        power[0] = 1;
        
        for(int i=1; i<=n; i++){
            power[i] = (power[i-1] * 2) %md;        
        }

        int i = 0, j = n-1;
        int ans = 0;
        while(i<=j){
            if((nums[i] + nums[j]) <= target){
                ans += power[j-i];
                ans %= md;
                i++;
            }
            else j--;
        }
        return ans;
    }
    
};