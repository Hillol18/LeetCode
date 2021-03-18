/*
[[1,2,3,4],
[4,5,6,23],
[7,8,9,22],
[7,8,9,12]]

[[7,7,4,1],
[8,6,5,2],
[9,6,9,3],
[12,22,23,4]]


[[3,6,1],
[4,5,2],
[7,8,9]]

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int u=0,l=0,r=n-1, d=n-1;
        int loop=0;
        while(u<d && l<r){
            int temp;
            for(int i=0;(i+l)<r;i++){
                temp = matrix[u][l+i];

                swap(temp, matrix[u+i][r]);
                swap(temp, matrix[d][r-i]);
                swap(temp, matrix[d-i][l]);
                swap(temp, matrix[u][l+i]);
            }
            //break;
            u++;
            d--;
            l++;
            r--;
        }
       //return matrix;
    }
};
