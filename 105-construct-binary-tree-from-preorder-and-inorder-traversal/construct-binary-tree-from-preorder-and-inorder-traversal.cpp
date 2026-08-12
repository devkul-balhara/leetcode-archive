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

    TreeNode* rec(vector<int>& pre, vector<int>& in, int ps, int pe, int is, int ie, map<int,int>& in_map){
        if(ps > pe || is > ie) return NULL;
        int in_idx = in_map[pre[ps]]; // current root index in pre = ps
        int left = in_idx-is; // no of nodes in left subtree of root 
        TreeNode* root = new TreeNode(pre[ps]);
        root->left = rec(pre,in,ps+1,ps+left,is,in_idx-1,in_map);
        root->right = rec(pre,in,ps+left+1,pe,in_idx+1,ie,in_map);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size()) return NULL;
        map<int,int> in_map; // node value,idx
        for(int i = 0; i < inorder.size(); i++) in_map[inorder[i]] = i;
        return rec(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,in_map);
    }
};