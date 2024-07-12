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
    int sumOfLeftLeaves(TreeNode* root) {
        int answer = 0;

        if(root->left != nullptr)
            answer += sum(root->left, true);
        if(root->right != nullptr)
            answer += sum(root->right, false);

        return answer;
    }

    int sum(TreeNode* root, bool left_leaf) {
        int answer = 0;

        if(left_leaf)
        {
            if(root->left == nullptr && root->right == nullptr)
                answer = root->val;
        }

        if(root->left != nullptr)
            answer += sum(root->left, true);
        if(root->right != nullptr)
            answer += sum(root->right, false);

        return answer;
    }
};