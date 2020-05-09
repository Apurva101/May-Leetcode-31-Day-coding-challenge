/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
 Check if these points make a straight line in the XY plane.
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
      float slope;
        if(coordinates.size()<=2)
            return true;
        if((coordinates[1][0]-coordinates[0][0])!=0)
         slope=float(coordinates[1][1]-coordinates[0][1])/float(coordinates[1][0]-coordinates[0][0]);
      //  cout<<slope<<" ";
        for(int i=2;i<coordinates.size();++i)
        {
    if((coordinates[i][0]-coordinates[i-1][0])!=0)
            if((float(coordinates[i][1]-coordinates[i-1][1])/float(coordinates[i][0]-coordinates[i-1][0]))!=slope)
            return false;
        }
        
        return true;
    }
};
