/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
*/

class Solution {
public:
    
    bool isPermutation(string s1,string s2)
    {
     int mp[26]={0};
        for(int i=0;i<s1.length();++i)
            mp[s1[i]-'a']++;
        
        for(int i=0;i<s2.length();++i)
        {
            mp[s2[i]-'a']--;
        }
        
        for(auto it:mp)
        {
            if(it>0)
            {
                return false;
             
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        if(n>s2.length())
            return false;
        for(int i=0;i<s2.length()-n+1;++i)
        {
            
            if(isPermutation(s1,s2.substr(i,n)))
            {
              
                return true;
             
            }
            
        }
        
        return false;
    }
};
