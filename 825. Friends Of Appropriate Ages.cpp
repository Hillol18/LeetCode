/*


age[y] > age[x]
age[y] > 100 && age[x] < 100

14-7-14

14


age[y] <= age[x]
age[y] > (0.5 * age[x] + 7)



age[y] >= age[x] && (age[y] > age[100] 
[17,17,17,17,18,18,19,19]
12 + 10 + 14


*/

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        
        sort(ages.begin(), ages.end());
        int cnt = 0;
        int n = ages.size();
        
        if(n <= 1) return 0;
        
        int ans = 0;
        auto it = ages.begin();
        
        while(it != ages.end()){
            auto it2 = upper_bound(ages.begin(), ages.end(), *it);
            int items = it2 - it;

            it2--;
            auto it3 = lower_bound(ages.begin(), it2, (*it) / 2 + 8);
            
            ans += (it2-it3) * items;
            
            //cout<<items<<" "<<(it2-it3)<<endl;
            it2++;
            it = it2;
        }
        return ans;
    }
};