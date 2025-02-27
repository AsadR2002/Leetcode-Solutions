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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> ans; 
            if(root == NULL) return ans; 
    
            deque<TreeNode*> dq; 
            dq.push_front(root); 
            while(!dq.empty()){
                int size = dq.size(); 
                vector<int> iter; 
                for(int i = 0; i < size; i++){
                    TreeNode* temp = dq.back();
                    dq.pop_back(); 
                    if(temp->left) dq.push_front(temp->left);
                    if(temp->right) dq.push_front(temp->right);
                    iter.push_back(temp->val);
                }
                ans.push_back(iter);
            }
            return ans;
        }
};