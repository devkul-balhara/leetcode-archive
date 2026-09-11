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
    pair<int,int> cal(TreeNode* node, int& ans){
        if(node == NULL) return {0,0};
        pair<int,int> pl = cal(node->left, ans);
        pair<int,int> pr = cal(node->right, ans);
        int sum = node->val+pl.first+pr.first, num = 1+pl.second+pr.second;
        if((sum == 0 && num == 0) || (num != 0 && node->val == sum/num)) ans++;
        return {sum,num};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        cal(root, ans);
        return ans;
    }
};