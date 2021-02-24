class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n= A.size();
        int sum = 0;
        for(int i=0;i<n-2;i++){
            if((A[i]-A[i+1]) == (A[i+1] - A[i+2])){
                int dif=A[i]-A[i+1];
                int cnt=1;
                int j=i+3;
                while(j<n && (A[j-1]-A[j]) == dif){
                    cnt++;
                    j++;
                }

                i=j-1;
                //cout<<cnt<<endl;
                sum += cnt*(cnt+1)/2;
            }
        }
        return sum;
    }
};
