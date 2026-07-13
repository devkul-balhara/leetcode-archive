/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root, int val, string &path) {
        if (root == nullptr) return false;
        if (root->val == val) return true;

        // explore left 
        path.push_back('L');
        if (findPath(root->left, val, path)) return true;
        path.pop_back();

        // explore right
        path.push_back('R');
        if (findPath(root->right, val, path)) return true;
        path.pop_back();

        // path not found
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;

        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        int i = 0;

        while (i < startPath.size() && i < destPath.size() && startPath[i] == destPath[i]) {
            i++;
        }

        string ans;

        // Move from start up to LCA
        ans.append(startPath.size() - i, 'U');

        // Move from LCA to destination
        ans += destPath.substr(i);

        return ans;
    }
};

/*
Find the path from root → start
Find the path from root → dest
Remove the common prefix (which represents the path to the LCA).
Convert the remaining part of root → start into 'U'.
Append the remaining part of root → dest.
*/