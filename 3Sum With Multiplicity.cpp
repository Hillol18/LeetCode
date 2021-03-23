class Solution {
public:



    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        int m = target;

        int ans = 0;
        int md = 1000000007;
        sort(arr.begin(), arr.end());
        for(int i=0;i<n-2;i++){
            int lw=i+1,hg=n-1;
            while(lw<hg){
                int sum = arr[i]+arr[lw]+arr[hg];
                if(sum == target){
                    int lwCnt = 1, hgCnt=1;
                    while(lw<hg && arr[lw]==arr[lw+1]){lw++; lwCnt++;}
                    while(lw<hg && arr[hg]==arr[hg-1]){hg--; hgCnt++;}

                    //cout<<lwCnt<<" "<<hgCnt<<endl;
                    if(lw==hg){
                        lwCnt--;
                        ans +=(lwCnt*(lwCnt+1))/2;
                    }
                    else{
                        ans+=(lwCnt*hgCnt);
                        lw++;
                        hg--;
                    }
                    ans%=md;
                }
                else if(sum > target){
                    hg--;
                }
                else{

                    lw++;
                }
            }
        }
        return ans;

    }
};
