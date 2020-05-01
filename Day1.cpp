class Solution {
public:
    int helperfunc(int start, int end)
    {   if(start>=end)
        return start;
       
        int mid=start+(end-start)/2;
     
        if(isBadVersion(mid))
        {  
            
               return helperfunc(start,mid);
            
        }
        else
        {
           
            return helperfunc(mid+1,end);
            
        }
            
    }
    int firstBadVersion(int n) {
        
        return helperfunc(1,n);
        
    }
};
