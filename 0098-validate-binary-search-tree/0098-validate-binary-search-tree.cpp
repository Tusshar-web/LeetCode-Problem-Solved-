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
    bool isValidBST(TreeNode* root) {
        return isValidBst(root, LLONG_MIN , LLONG_MAX);
    }
    bool isValidBst(TreeNode* root , long long minVal , long long maxVal){
        if(root == NULL) return true;
        if(root->val >= maxVal || root->val <= minVal) return false;

        return isValidBst(root->left , minVal , root->val) && isValidBst(root->right , root->val , maxVal);
    }
};