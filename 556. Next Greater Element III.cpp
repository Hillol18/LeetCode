class Solution {
public:
    int nextGreaterElement(int n) {
        string number = to_string(n);
        int i = number.size()-1;
        int dif=-2;
        while(i>=0 && number[i]>=number[i+1]){
            i--;
        }


        if(i<0)
            return -1;
        int k=-1;
        for(int j=i+1;j<number.size();j++){
            if(k==-1 || (number[k] > number[j] && number[j] > number[i] ) ){
                k=j;
            }
        }

        swap(number[k], number[i]);

        sort(number.begin()+i+1, number.end());
        cout<<number<<endl;
        long long int d = stoll(number);
        if(d>INT_MAX || d<1) return -1;
        //cout<<INT_MAX<<" "<<(1L<<31)-1<<" "<<stoi(to_string((1L<<31) -1))<<endl;
        return d;

    }
};
