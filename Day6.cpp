/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();++i)
        {
            mp[nums[i]]++;
        }
        int ans;
        for(auto it=mp.begin();it!=mp.end();++it)
        {
            if(it->second>floor(nums.size()/2))
            {ans= it->first;
             break;
            }
        }
        
        return ans;
    }
};
