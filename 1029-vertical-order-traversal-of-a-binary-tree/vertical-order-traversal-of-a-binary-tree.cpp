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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // vertical level -> {horizontal level, value}
        map<int,vector<pair<int,int>>> mp;
        // {node,vertical level}
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        // hlevel is horizontal level
        int hlevel = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                int vlevel = q.front().second;
                TreeNode* curr = q.front().first;
                q.pop();
                mp[vlevel].push_back({hlevel,curr->val});
                if(curr->left) q.push({curr->left,vlevel-1});
                if(curr->right) q.push({curr->right,vlevel+1});
            }
            hlevel++;
        }
        vector<vector<int>> ans;
        for(auto i : mp){
            vector<int> v;
            sort(i.second.begin(),i.second.end());
            for(auto j : i.second) v.push_back(j.second);
            ans.push_back(v); 
        }
        return ans;
    }
};