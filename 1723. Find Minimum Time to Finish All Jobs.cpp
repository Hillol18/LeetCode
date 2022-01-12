/*
11111
01234

*/
class Solution {
public:
    
    bool isPossible(int pos, vector<int> &sum, vector<int> &jobs, int &k, int &target){        
        
        if(pos == jobs.size()){
            return 1;
        }
        
        int ret = 0;
        
        for(int i = 0; i<k && ret == 0; i++){
            if((sum[i] + jobs[pos]) <= target){
                sum[i] += jobs[pos];
                ret |= isPossible(pos + 1, sum, jobs, k, target);
                sum[i] -= jobs[pos];
            }
            
            if(sum[i] == 0) break;
        }
        
        return ret;
    }
    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int sum = 0;
        for(int i = 0; i<jobs.size(); i++){
            sum += jobs[i];
        }
       
        int n = jobs.size();
        sort(jobs.begin(),jobs.end(),greater<int>());
        int low = jobs[0], high = sum;
        int ans = 0;

        while(low <= high){
            int mid = (low + high) / 2;
            vector<int> sum(k + 1, 0);     
            int state = isPossible(0, sum, jobs, k, mid);
            
            if(state){
                ans = mid;
                high = mid -1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};