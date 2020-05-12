/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]

*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
       if(trust.size()==0)
           return 1;
        unordered_map<int, pair<int,int> > mp;
        
        for(int i=0; i<trust.size(); ++i)
        {
            mp[trust[i][1]].first++;
            
            mp[trust[i][0]].second++;
            
           
        }
        
        for(auto it=mp.begin(); it!=mp.end();++it)
        {    pair<int,int> p1=it->second;
            if(p1.first==N-1 && p1.second==0)
            {
                return it->first;
            }
        }
        
        return -1;
    }
};
