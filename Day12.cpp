/*

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];
        
        int low=0,high=nums.size()-1;
        
        while(low<=high)
        {
            int mid=((high-low)/2)+low;
            if(mid==0)
                return nums[0];
            if(mid==high)
                return nums[high];
            if(mid-1>=0 && mid+1<nums.size() && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            else if((mid+1<nums.size() && nums[mid]==nums[mid+1] && mid%2!=0) ||                         (mid-1>=0 && nums[mid]==nums[mid-1] && mid%2==0))
                high=mid-1;
            else
                low=mid+1;
        }
        return nums[low];
    }
};
