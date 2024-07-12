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
    bool isSymmetric(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            return true;
        else if(root->left != nullptr && root->right != nullptr)
            return checkSymmetric(root->left, root->right);
        else
            return false;
    }
    bool checkSymmetric(TreeNode* left, TreeNode* right) {
        bool left_ok = false;
        bool right_ok = false;

        if(left->val != right->val)
            return false;
                
        if(left->left != nullptr && right->right != nullptr)
            left_ok = checkSymmetric(left->left, right->right);
        if(left->left == nullptr && right->right == nullptr)
            left_ok = true;

        if(left->right != nullptr && right->left != nullptr)
            right_ok = checkSymmetric(left->right, right->left);
        if(left->right == nullptr && right->left == nullptr)
            right_ok = true;

        if(left_ok && right_ok)
            return true;

        return false;
    }
};