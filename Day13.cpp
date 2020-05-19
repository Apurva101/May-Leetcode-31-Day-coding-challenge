/*

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be = k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        //int start=0;
        if(num.length()==1)
            return "0";
        while(k>0)
        {   k--;
         int i;
          for( i=0;i<num.length()-1;++i)
            {
                if(num[i]>num[i+1])
                {
                    
                   // start=i+1;
                    break;
                }
            }
         num.erase(i,1);
       
        }   
       int j=0;
        while(j<num.length() && num[j]=='0')
            num.erase(j,1);
         if(num=="")
            num+='0';
        return num;
    }
};
