/*

46/23
*/

class Solution {
public:

    bool is2Pow(int num, vector<int> &d){
        vector<int>cnt(10);
        while(num){
            int d = num%10;
            cnt[d]++;
            num/=10;
        }

        for(int i=0;i<=9;i++){
            if(cnt[i] != d[i]) return false;
        }
        return true;
    }

    bool reorderedPowerOf2(int N) {

        vector<int> cnt(10,0);

        while(N){
            int d = N%10;
            cnt[d]++;
            N/=10;
        }
        long range = 0;
        for(int i=9;i>=0;i--){
            for(int j=0;j<cnt[i];j++){
                range*=10;
                range+=i;
            }
        }

        long int temp = 1;
        while(temp<=range){
            if(is2Pow(temp,cnt)) return true;
            temp=temp<<1;
        }
        return false;
    }
};
