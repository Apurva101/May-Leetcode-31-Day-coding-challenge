/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
 */
class Solution {
public:
     unordered_map<int,int> color;
    
        
    bool dfs(vector<vector<int>>&graph,int i, int c)
    {
        if(color.find(i)!=color.end())
            return color[i]==c;
        else color[i]=c;
        
        for(int n:graph[i])
            if(!dfs(graph,n,c^1))
               return false;
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
       
        vector<vector<int>> graph(N+1);
        for(auto it: dislikes)
        {
            
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
   
        
        for(int i=1;i<=N;++i)
        {
            if(color.find(i)==color.end() && !dfs(graph,i,0))
                return false;
        }
        return true;
        
       
    }
};
