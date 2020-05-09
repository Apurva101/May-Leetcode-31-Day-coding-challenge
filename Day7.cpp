/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* parx=NULL;
        TreeNode* pary=NULL;
        
        queue<pair<TreeNode*,TreeNode*> > q;
        TreeNode* temp=new TreeNode(-1);
      //  pair<TreeNode*, TreeNode*> p;
        q.push(make_pair(root,temp));
        while(!q.empty())
        {
            int levelsize=q.size();
            
            while(levelsize)
            {
                pair<TreeNode*, TreeNode*> p1=q.front();
                q.pop();
                if(p1.first->val==x)
                    parx=p1.second;
                if(p1.first->val==y)
                    pary=p1.second;
                if(p1.first->left)
                    q.push(make_pair(p1.first->left, p1.first));
                if(p1.first->right)
                    q.push(make_pair(p1.first->right, p1.first));
                    levelsize--;
                
                if(parx && pary)
                    break;
            }
            
            if(parx && pary)
                return (parx!=pary);
            
            if((parx && !pary) || (!parx && pary))
                return false;
        }
        
        return false;
    }
};
