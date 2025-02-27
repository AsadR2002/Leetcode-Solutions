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
        bool isSameTree(TreeNode* p, TreeNode* q) {
        
                if(!p && !q) return true; 
                if(!p || !q) return false; 
        
                if(p->val != q->val) {
                    return false;
                }
        
                return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)); 
        }
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            queue<TreeNode*> q; 
            if(root == NULL && subRoot == NULL) return true;
            if(root == NULL || subRoot == NULL) return false;
    
            q.push(root); 
    
            while(!q.empty()){
                TreeNode* node = q.front(); 
                q.pop();
                if(isSameTree(node, subRoot)) return true;
                if(node) {
                    q.push(node->left); 
                    q.push(node->right);
                }
            }
            return false;
            
        }
};