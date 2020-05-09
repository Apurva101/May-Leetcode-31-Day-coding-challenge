/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true

*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int start=1,end=num;
        
        while(start<=end)
        {
            long mid=(end-start)/2+start;
            
            if(mid*mid==num)
                return true;
            else if(mid*mid<num)
                start= int(mid)+1;
            else
                end=int(mid)-1;
        }
        
        return false;
    }
};
