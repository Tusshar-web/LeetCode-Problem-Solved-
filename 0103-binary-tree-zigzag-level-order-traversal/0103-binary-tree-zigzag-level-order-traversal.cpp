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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;

        queue<TreeNode*> nq;
        nq.push(root);

        bool leftToRight = true;

        while(!nq.empty()){
            int size = nq.size();
            vector<int> row(size);

            for(int i = 0; i < size; i++){
                TreeNode* node = nq.front();
                nq.pop();

                int ind = leftToRight ? i : (size - i - 1);
                row[ind] = node->val;

                if(node->left){
                    nq.push(node->left);
                }
                if(node->right){
                    nq.push(node->right);
                }
            }

            leftToRight = !leftToRight;
            res.push_back(row);
        }
        return res;
    }
};