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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long minInd = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                unsigned long long curInd = q.front().second - minInd;
                q.pop();

                if (i == 0) first = curInd;
                if (i == size - 1) last = curInd;

                if (node->left)
                    q.push({node->left, curInd * 2 + 1});

                if (node->right)
                    q.push({node->right, curInd * 2 + 2});
            }

            ans = max(ans, static_cast<int>(last - first + 1));
        }

        return ans;
    }
};