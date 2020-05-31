/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

*/

class Solution {
public:
    void inorder(vector<int>& inorderarr,TreeNode* root)
    {  if(root==NULL)
        return ;
         inorder(inorderarr,root->left);
        inorderarr.push_back(root->val);
        inorder(inorderarr,root->right);
        
        
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
            return 0;
        vector<int> inorderarr;
        
        inorder(inorderarr,root);
        
        return inorderarr[k-1];
    }
};
