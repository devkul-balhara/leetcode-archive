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
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* t = q.front();
                q.pop();
                if(t == NULL) ans += "#,";
                else{
                    ans += to_string(t->val)+',';
                    q.push(t->left);
                    q.push(t->right);
                }
            }
        }
        return ans;
    }

    string getToken(string &data, int &i){
        string temp = "";
        while(i < data.size() && data[i] != ','){
            temp.push_back(data[i]);
            i++;
        }
        i++; // skip comma
        return temp;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        int i = 0;
        string first = getToken(data,i);
        if (first == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(first));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            // LEFT
            string leftVal = getToken(data, i);
            if (leftVal != "#") {
                TreeNode* leftNode = new TreeNode(stoi(leftVal));
                node->left = leftNode;
                q.push(leftNode);
            }

            // RIGHT
            string rightVal = getToken(data, i);
            if (rightVal != "#") {
                TreeNode* rightNode = new TreeNode(stoi(rightVal));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));