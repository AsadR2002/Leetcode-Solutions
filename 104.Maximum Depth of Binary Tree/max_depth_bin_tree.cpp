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
        int maxDepth(TreeNode* root) {
            if(!root) return 0; 
    
            int level = 0; 
    
            deque<TreeNode*> q; 
            q.push_front(root);
    
            while(!q.empty()) {
                int size = q.size();
                for(int i = 0; i < size; i++) {
    
                    TreeNode* node = q.back();
                    q.pop_back();
                    if(node->left) q.push_front(node->left);
                    if (node->right) q.push_front(node->right);
                }
                level++;
            }
            return level;
        }
};