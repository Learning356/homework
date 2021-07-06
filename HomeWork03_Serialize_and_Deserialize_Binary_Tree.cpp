/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> level_queue;
        if(root == nullptr) return result.append("null ");
        level_queue.push(root);
        
        while(level_queue.size() != 0){
            //out queue
            TreeNode* node = level_queue.front();
            level_queue.pop();
            string content;
            if(node != nullptr) 
            {
                content = to_string(node->val);
                level_queue.push(node->left);
                level_queue.push(node->right);
                
            }
            else    
            {
                content = "null";
            }
            
            result.append(content.append(" "));
            
           
            
            
        }
        cout <<"result of serialize: " << result << endl;
        
        return result;
        
        
    }
    
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* res = nullptr;
        int start = 0;
        int end = data.find(" ");
        queue<TreeNode *> level_queue;
        string content = data.substr(start,end - start);
        if(content.compare("null") == 0){
            return res;
        }
        res = new TreeNode(stoi(content));
        level_queue.push(res);
//cout << "content: " <<content << " start: " << start << " end: " << end << endl;
        start = ++end;
        end = data.find(" ",start);
//cout << "content: " <<content << " start: " << start << " end: " << end << endl;
        while(end != data.size()-1 && level_queue.size() != 0){
            //取出对头
            TreeNode* node = level_queue.front();
            //出队
            level_queue.pop();
            if(node == nullptr) continue;
            //取出两个值
            string left = data.substr(start,end-start);
            start = ++end;
            end = data.find(" ",start);
            string right = data.substr(start,end-start);
            start = ++end;
            end = data.find(" ",start);
            //把其建树中
             TreeNode* left_node = nullptr;
            TreeNode* right_node = nullptr;
            //left
            //cout << left <<" " << right;
            if(left.compare("null") != 0){
                int val = stoi(left);
                left_node = new TreeNode(val);
            }
            //right
            if(right.compare("null") != 0){
                int val = stoi(right);
                right_node = new TreeNode(val);
            }
            node->left = left_node;
            node->right = right_node;
            //入队
            level_queue.push(left_node);
            level_queue.push(right_node);
            
             
            
        }
        
        
        
        return res;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));