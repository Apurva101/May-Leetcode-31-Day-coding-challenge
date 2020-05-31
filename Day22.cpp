/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

*/

class Solution {
public:
static bool compare(pair<char,int> p1, pair<char,int>p2){
        return p2.second<p1.second;
 }
        
    string frequencySort(string s) {
        int n=s.length();
        string ans="";
        unordered_map<char, int> mp;
        for(int i=0;i<n;++i)
            mp[s[i]]++;
        vector<pair<char, int>> temp(mp.begin(), mp.end());
        sort(temp.begin(), temp.end(), compare);
        int i=0;
        
        for(auto it:temp)
        {  
            while(it.second){
            ans+=it.first;
             it.second--;   
            }
            
        }
        return ans;
        
    }
};
