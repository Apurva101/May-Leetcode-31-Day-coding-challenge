/*

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Example 1:

Input: 5
Output: 2

*/


class Solution {
public:
    int findComplement(int num) {
       if(num==0)
           return 0;
        int res=0;
        int count=log2(num);
        for(int i=0;i<count;++i)
        {
            if(!(num & 1<<i))
                res+=1<<i;
        }
        return res;
    }
};
