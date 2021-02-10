/*
Hillol
*/

/**
We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid.

A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.(Note that the rotated number can be greater than the original number.)

Given a positive integer N, return the number of confusing numbers between 1 and N inclusive.



Example 1:

Input: 20
Output: 6
Explanation:
The confusing numbers are [6,9,10,16,18,19].
6 converts to 9.
9 converts to 6.
10 converts to 01 which is just 1.
16 converts to 91.
18 converts to 81.
19 converts to 61.
**/

class Solution {
public:
    int fun(int pos,bool flag, string &limit, int pre, vector<int>&digit){
        if(limit.size() == pos){
          int rotate = 0;
            string s = to_string(pre);
            int i=s.size()-1;
            while(i>=0){
                int ind =(s[i]-'0');
                if(ind ==6)ind=9;
                else if(ind==9)ind=6;
                rotate *=10;
                rotate +=ind;
                i--;
            }
            if(pre != rotate){
                return 1;
            }

            return 0;
        }

        int h=digit[4];

        if(!flag){
            h=limit[pos]-'0';
        }

        int ret = 0;
        for(int i=0; i<5 && digit[i]<=h; i++){

           ret += fun(pos+1, flag|(!(digit[i]==h)), limit, pre*10 + digit[i], digit);
        }

        return ret;
    }

    int confusingNumberII(int N) {
        vector<int> digit (5);
        digit[0]=0;
        digit[1]=1;
        digit[2]=6;
        digit[3]=8;
        digit[4]=9;
        string limit = to_string(N);
        return fun(0, 0, limit,0,digit);
    }
};
