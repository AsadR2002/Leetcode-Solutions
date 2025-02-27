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
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if(preorder.size() == 0|| inorder.size() == 0) return NULL; 
    
            TreeNode* root = new TreeNode(preorder[0]); 
            auto it = find(inorder.begin(), inorder.end(), preorder[0]);
            int mid = distance(inorder.begin(), it);  
            vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + mid);
            vector<int> leftInorder(inorder.begin(), inorder.begin() + mid);
            vector<int> rightPreorder(preorder.begin() + 1 + mid, preorder.end());
            vector<int> rightInorder(inorder.begin() + mid + 1, inorder.end());
    
            // Recursively build left and right subtrees
            root->left = buildTree(leftPreorder, leftInorder);
            root->right = buildTree(rightPreorder, rightInorder);
    
            return root;
        }
};