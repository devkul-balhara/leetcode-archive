class Solution {
public:

    TreeNode* delsucc(TreeNode* root){
        bool ok = false;
        TreeNode* parent = root;
        root = root->right;
        while(root != NULL && root->left != NULL){
            ok = true;
            parent = root;
            root = root->left;
        }
        if(ok) parent->left = root->right;
        else parent->right = root->right;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else{
            // Node found

            // Case 1: no left child
            if (!root->left){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2: no right child
            if (!root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: both children
            TreeNode* succ = delsucc(root);
            root->val = succ->val;
            delete succ;
        }
        return root;
    }
};