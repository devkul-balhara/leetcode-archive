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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        vector<vector<int>> level;
        while(!q.empty()){
            int s = q.size();
            vector<int> v;
            for(int i = 0; i < s; i++){
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level.push_back(v);
        }
        for(auto i : level){
            vector<int> v(i);
            sort(v.begin(),v.end());
            if(i == v) continue;
            else{
                map<int,int> in, fin;
                for(int j = 0; j < i.size(); j++){
                    in[i[j]] = j;
                    fin[v[j]] = j;
                }
                map<int,int> mp;
                for(int j = 0; j < i.size(); j++){
                    mp[in[i[j]]] = fin[i[j]];
                }
                int cnt = 1;
                while(!mp.empty()){
                    auto it = mp.begin();
                    int f = it->first, s = it->second;
                    mp.erase(it);
                    while(s != f){
                        cnt++;
                        int temp = mp[s];
                        mp.erase(s);
                        s = temp;
                    }
                }
                cnt--;
                ans += cnt;
            }
        }
        return ans;
    }
};