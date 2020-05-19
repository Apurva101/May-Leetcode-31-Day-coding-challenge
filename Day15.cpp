/*
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size()==0)
            return 0;
        else
            if(A.size()==1)
                return A[0];
        int maxsum=A[0];
        int currmax=A[0];
        int currmin=A[0];
        int minsum=A[0];
        int n=A.size();
        int total=A[0];
        for(int i=1;i<n;++i)
        {
            currmax=max(A[i],currmax+A[i]);
            currmin=min(A[i],currmin+A[i]);
            if(currmax>maxsum)
                maxsum=currmax;
            if(currmin<minsum)
                minsum=currmin;
            total+=A[i];
           
        }
    
        if(maxsum>0)
           return max(maxsum,total-minsum);
        return maxsum;
    }
};
