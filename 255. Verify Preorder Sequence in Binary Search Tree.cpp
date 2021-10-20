class Solution {
public:
    
    bool isSatisfy(pair<int,int> it1, pair<int,int> it2){
        if(it1.second < it2.first) return true;
        return false;
    }
    
    pair<int, int> dfs(int left, int right, vector<int> &arr, bool &ans){
        
        
        int cnt = 0;
        int total = right-left;
        
        if(left == right) return make_pair(arr[left], arr[right]);
        
        auto ret = make_pair(arr[left], arr[left]);
        
        bool flag = false;
        
        int i = left;
        i++;
        while(i <= right && arr[i] < arr[left]) {
            i++;
            cnt++;    
        };
        
        bool temp = true;
        if(cnt){
           auto it1 = dfs(left+1, left+cnt, arr, ans);
            if(!isSatisfy(it1, ret)){
                temp = false;
            }

            ret.first = min(ret.first, it1.first);
            ret.second = max(ret.second, it1.second);
        }

        if(total - cnt > 1){
            auto it2 = dfs(left+cnt+1, right, arr, ans);

            if(!isSatisfy(ret, it2)){
                temp = false;
            }

            ret.first = min(ret.first, it2.first);
            ret.second = max(ret.second, it2.second);
        }

        ans&= temp; 
        return ret;
    }
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        bool ans = true;
        dfs(0,n-1, preorder, ans);
        return ans;
    }
};