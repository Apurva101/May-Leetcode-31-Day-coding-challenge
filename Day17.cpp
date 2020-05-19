/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> res;
        
        int n=p.length();
        
        unordered_map<char,int> mp;
        
        for( int i=0; i<n; ++i)
            mp[p[i]]++;
        
        int start=0,end=0;
        
        int match=p.length();
        
        while(end<s.length())
        {
          if(mp[s[end]]>0)
            {
              
                match--;
                
            }
              mp[s[end]]--;
            
            if((end-start+1)==n)
            {
                if( match == 0)
                res.push_back(start);
                
                if(mp[s[start]]>=0)
                match++;
                
                mp[s[start]]++;
                start++;
               
                
            }
            
            end++;
        }
        
        return res;
    }
};
