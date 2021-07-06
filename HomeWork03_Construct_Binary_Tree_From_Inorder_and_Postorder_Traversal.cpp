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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        
        
        return build(inorder, 0,inorder.size() - 1,postorder, 0,postorder.size() - 1);
    }
    TreeNode* build(vector<int>& inorder, int l1, int r1, vector<int>& postorder ,int l2, int r2){
        if(r2 < l2) return nullptr;
        TreeNode* node = new TreeNode(postorder[r2]);
        //inorder left node right
        //post order left right node
        //last node must be node
        int node_index = l1;
        while(postorder[r2] != inorder[node_index]){
            node_index++;
        }
        int left_size = node_index - l1;
        int right_size = r1 - node_index;
        
        node->right = build(inorder, node_index+1,r1, postorder ,r2 - right_size,r2-1);
        node->left = build(inorder, l1,node_index-1,postorder ,l2 , r2 - right_size -1);
        
        
        
        return node;
    }
};