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

 //recursive 
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root == NULL) return 0; 
    
            return 1 + max(maxDepth(root->left), maxDepth(root->right));      
        }
};

//dfs interative 
class Solution {
    public:
        int maxDepth(TreeNode* root) {
    
            if(root == NULL) return 0; 
            int max_depth = 0; 
            stack<pair<TreeNode*,int>> nodes;
    
            nodes.push({root, 1}); 
    
            while(!nodes.empty()){ 
                TreeNode* node = nodes.top().first; 
                int depth = nodes.top().second;
                nodes.pop(); 
    
                if(node) {
                    max_depth = max(max_depth, depth); 
                    nodes.push({node->left, depth + 1}); 
                    nodes.push({node->right, depth + 1}); 
                }
            }
            return max_depth;            
        }
};

//bfs interative 
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root == NULL) return 0; 
    
            int level = 0; 
    
            deque<TreeNode*> dq; 
            dq.push_front(root);
            while(!dq.empty()) {
                int size = dq.size();
                for(int i = 0; i < size; i++) {
                    TreeNode* temp = dq.back();
                    dq.pop_back();
                    if(temp->left) dq.push_front(temp->left);
                    if(temp->right) dq.push_front(temp->right);
                }
                level++;
            }
            return level; 
        }
};