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
    int ans = 0;
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        DFS(root,0);
        
        return ans+1;
    }
    
    void DFS(TreeNode* node, int level){
        if(node == nullptr){
            return ;
        }
        ans = max(ans, level);
        DFS(node->left, level+1);
        DFS(node->right, level+1);
    }
};