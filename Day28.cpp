/*
Given a non negative integer number num. For every numbers i in the range 0 = i = num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
 */
class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> dp;
        dp.push_back(0);
        
        for(int i=1;i<=num;++i)
        {
            if(i%2==0)
                dp.push_back(dp[i/2]);
            else
                dp.push_back(1+dp[i/2]);
        }
        return dp;
    
    }
};
