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
    bool isBalanced(TreeNode* root) {
        bool left_balance = false;
        bool right_balance = false;

        int left_height, right_height;

        if(root == nullptr)
            return true;

        if(root->left == nullptr)
        {
            left_height = 0;
            left_balance = true;
        }
        else
        {
            left_height = checkHeight(root->left);
            left_balance = isBalanced(root->left);
        }

        if(root->right == nullptr)
        {
            right_height = 0;
            right_balance = true;
        }
        else
        {
            right_height = checkHeight(root->right);
            right_balance = isBalanced(root->right);
        }

        if(left_balance && right_balance)
        {
            if(sub(left_height, right_height) <= 1)
                return true;
        }
        return false;        
    }

    int checkHeight(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            return 1;

        if(root->right == nullptr)
            return checkHeight(root->left) + 1;
        if(root->left == nullptr)
            return checkHeight(root->right) + 1;

        if(checkHeight(root->left) > checkHeight(root->right))
            return checkHeight(root->left) + 1;
        else
            return checkHeight(root->right) + 1;
    }

    int sub(int a, int b) {
        if(a > b)
            return a - b;
        else
            return b - a;
    }
};