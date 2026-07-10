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

    int amountOfTime(TreeNode* root, int start) {
        if(root == NULL) return 0;
        map<TreeNode*,TreeNode*> mp;
        dfs(root,mp);
        TreeNode* st = find(root,start);
        queue<TreeNode*> q;
        q.push(st);
        int ans = -1;    
        vector<bool> vis(1e5+1,false);
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                TreeNode* curr = q.front();
                q.pop();
                vis[curr->val] = true;
                if(curr->left && !vis[curr->left->val]) q.push(curr->left);
                if(curr->right && !vis[curr->right->val]) q.push(curr->right);
                if(mp.find(curr) != mp.end() && !vis[mp[curr]->val]) q.push(mp[curr]);
            }
            ans++;
        }
        return ans;
    }
};