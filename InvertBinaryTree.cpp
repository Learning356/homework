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
    TreeNode* invertTree(TreeNode* root) {
        
        flip_a_tree(root);
        
        
        return root;
        
    }
    void flip_a_tree(TreeNode* node){
         if(node == nullptr)  return;
        
        
        flip_a_tree(node->left);
        flip_a_tree(node->right);
        TreeNode* tmp = nullptr;
        tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        
        
        
    }
};