/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        int res = 0;
        int dfs(TreeNode* root) {
            if(root == NULL) return 0; 
    
            int leftmax = dfs(root->left); 
            int rightmax = dfs(root->right);
            leftmax = max(leftmax, 0);  
            rightmax = max(rightmax, 0);  
    
            res = max(leftmax+rightmax+root->val, res); 
            return root->val + max(leftmax, rightmax);
        }
        int maxPathSum(TreeNode* root) {
            res = root->val; 
    
            dfs(root); 
    
            return res; 
        }
};