/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]


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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        
        TreeNode* root=new TreeNode(preorder[0]);
        st.push(root);
        
        TreeNode* temp;
        int i;
        
        for(i=1; i<preorder.size();++i)
        { temp=NULL;
            while(!st.empty() && preorder[i]>st.top()->val)
            {temp=st.top();
             st.pop();
            }
            if(temp!=NULL)
            {
                temp->right=new TreeNode(preorder[i]);
                st.push(temp->right);
            }
            else
            {
                st.top()->left=new TreeNode(preorder[i]);
                st.push(st.top()->left);
            }
        }
        
        return root;
        
    }
};
