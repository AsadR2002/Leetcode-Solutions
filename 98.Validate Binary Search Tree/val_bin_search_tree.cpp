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
        bool valid(TreeNode* node, long leftbound, long rightbound) {
            if(node == NULL) return true; 
            if(!(node->val < rightbound) || !(node->val > leftbound)) return false; 
    
            return valid(node->left, leftbound, node->val) && valid(node->right, node->val, rightbound);
    
        }
        bool isValidBST(TreeNode* root) {
            return valid(root, LONG_MIN, LONG_MAX);
            
        }
};