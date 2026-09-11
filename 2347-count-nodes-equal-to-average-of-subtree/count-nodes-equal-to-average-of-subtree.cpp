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
    pair<int,int> cal(TreeNode* node){
        if(node == NULL) return {0,0};
        int sum = node->val, num = 1;
        pair<int,int> pl = cal(node->left);
        pair<int,int> pr = cal(node->right);
        sum += pl.first+pr.first;
        num += pl.second+pr.second;
        return {sum,num};
    }
    
    int find(TreeNode* node){
        if(node == NULL) return 0;
        int cnt = 0;
        pair<int,int> p = cal(node);
        int sum = p.first, num = p.second;
        if((sum == 0 && num == 0) || (num != 0 && node->val == sum/num)) cnt++;
        cnt += find(node->left);
        cnt += find(node->right);
        return cnt;
    }

    int averageOfSubtree(TreeNode* root) {
        return find(root);
    }
};