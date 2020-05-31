/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
 */
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        for(int i=0;i<nums.size();++i)
            if(nums[i]==0)
                nums[i]=-1;
        int sum=0;
        int length=0;
          unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            
          if(sum==0)
              length=i+1;
            
            if(mp.find(sum)!=mp.end())
            {
                if (length<i-mp[sum])
                {
                    length=i-mp[sum];
                   // mp[sum]=length;
                }
                
            }
            else
                mp[sum]=i;
        }
        
        return length;
    }
};
