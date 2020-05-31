/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15

*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        
        //dp[0][0]=matrix[0][0];
     //   dp[0][1]=matrix[0][1];
       // dp[1][0]=matrix[1][0];
        for(int i=0;i<n;++i)
            dp[0][i]=matrix[0][i];
        for(int j=1; j<m;++j)
            dp[j][0]=matrix[j][0];
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {  if(matrix[i][j]==1)
                dp[i][j]=1+min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
        int sum=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
                sum+=dp[i][j];
        }
        return sum;
    }
};
