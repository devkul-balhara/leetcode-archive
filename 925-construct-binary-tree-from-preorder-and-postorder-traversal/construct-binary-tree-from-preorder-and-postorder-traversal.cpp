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
    TreeNode* build(vector<int>& pre, vector<int>& post, int pres, int pree, int posts, int poste, unordered_map<int,int>& post_map){
        if(pres > pree || posts > poste) return NULL;
        if(pres == pree) return new TreeNode(pre[pres]);
        int post_idx = post_map[pre[pres+1]]; // index of curr's left node in post
        int left = post_idx-posts+1; // including the curr's left
        TreeNode* root = new TreeNode(pre[pres]);
        root->left = build(pre,post,pres+1,pres+left,posts,post_idx,post_map);
        root->right = build(pre,post,pres+left+1,pree,post_idx+1,poste,post_map);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> post_map;
        for(int i = 0; i < preorder.size(); i++) post_map[postorder[i]] = i;
        return build(preorder,postorder,0,preorder.size()-1,0,postorder.size()-1,post_map);
    }
};