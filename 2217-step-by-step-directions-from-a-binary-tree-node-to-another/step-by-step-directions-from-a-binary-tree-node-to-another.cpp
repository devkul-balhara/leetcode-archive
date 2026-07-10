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
    void dfs(TreeNode* root, map<TreeNode*,TreeNode*>& mp){
        if(!root) return;
        dfs(root->left,mp);
        dfs(root->right,mp);
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
    }

    TreeNode* find(TreeNode* root, int start){
        if(root == NULL) return NULL;
        if(root->val == start) return root;
        TreeNode* left = find(root->left,start);
        TreeNode* right = find(root->right,start);
        if(left) return left;
        else return right;
    }

    bool searchPath(TreeNode* curr, int destValue, map<TreeNode*,TreeNode*>& mp, vector<bool>& vis, string& path) {
        if(curr->val == destValue) return true; // Found the destination!
        vis[curr->val] = true;
        // Try moving Left
        if(curr->left && !vis[curr->left->val]) {
            path += 'L'; // Add letter to our single string
            if(searchPath(curr->left, destValue, mp, vis, path)) return true;
            path.pop_back(); // Dead end? Remove the letter (Backtrack)
        }
        // Try moving Right
        if(curr->right && !vis[curr->right->val]) {
            path += 'R';
            if(searchPath(curr->right, destValue, mp, vis, path)) return true;
            path.pop_back(); 
        }
        // Try moving Up
        if(mp.find(curr) != mp.end() && !vis[mp[curr]->val]) {
            path += 'U';
            if(searchPath(mp[curr], destValue, mp, vis, path)) return true;
            path.pop_back(); 
        }
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(root == NULL) return "";
        map<TreeNode*,TreeNode*> mp;
        dfs(root,mp);
        TreeNode* st = find(root, startValue);
        string ans;
        vector<bool> vis(1e5+1, false);
        searchPath(st, destValue, mp, vis, ans);
        return ans;
    }
};