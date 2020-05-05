/*Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        
        for(int i=0;i<s.length();++i)
        {
            if(mp.find(s[i])==mp.end())
                mp[s[i]]=i;
            else
                mp[s[i]]=-1;
        }
        
        int ans=INT_MAX;
        for(auto it=mp.begin();it!=mp.end();++it)
        {  if(it->second!=-1)
            ans=min(ans,it->second);
         
        }
        if(ans==INT_MAX)
            ans=-1;
        
        return ans;
    }
};
