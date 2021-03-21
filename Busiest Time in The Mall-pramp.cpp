#include <iostream>
#include <vector>

using namespace std;
//https://www.linkedin.com/in/vaibhavv06/
int findBusiestPeriod( const vector<vector<int> >& data )
{
  int outputTS =-1;
  int maxCount = 0;
  int n = data.size();
  int currSum = 0;
  int currTS;
  for(int i=0;i<n;i++){


    if(data[i][2]==1){
     currSum += data[i][1];
    }
    else{
      currSum -= data[i][1];
    }

    currTS = data[i][0];

    if(i==(n-1) || data[i][0] != data[i+1][0]){
      if(currSum > maxCount){
        maxCount = currSum;
        outputTS = currTS;
      }
    }

  }


  return outputTS;
}

int main() {
  return 0;
}
/*
The values at indices 0, 1 and 2 are the timestamp, the count of visitors, and whether the visitors entered or exited the mall (0 for exit and 1 for entrance), respectively
returns the time at which the mall reached its busiest moment last year
currentCount = 8;
output = 1487799425

1487801478
count
data =         [ [1487799425, 14, 1], -> 14
                 [1487799425, 4,  0], -> 10
                 [1487799425, 2,  0], ->  8
                 [1487800378, 10, 1], -> 18 -
                 [1487800378, 18, 0], ->  0 -
                 [1487801478, 18, 1], -> 18 -
                 [1487901013, 1,  0],
                 [1487901211, 7,  1],
                 [1487901211, 7,  0] ]



*/
