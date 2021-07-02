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
    bool ans = true;
    long long val[2];
    bool isValidBST(TreeNode* root) {
        val[0] = 0;
        val[1] = INT_MIN;
        research_BSF(root);
        
       
        return ans;
        
    }
    
    void research_BSF(TreeNode * node){
        
       
         if(node == nullptr ) return;
        
        //进行中序遍历，发现非上升
       // val[1] = min(val[0],node->val);
       // val[0] = max(val[1],node->val);
        
       // if(val[0] >= node->val) ans = false;
        
       // if(val[1] <= node->val) ans = false;
        research_BSF(node->left);
        val[0] = val[1] ;
        val[1] = (long long)node->val + 1;
        if(val[1] <= val[0]) ans = false; 
        //cout << node->val;
        research_BSF(node->right);
        
        
        
        
        
    }

};