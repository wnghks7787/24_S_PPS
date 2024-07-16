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
    int diameterOfBinaryTree(TreeNode* root) {
        int left_diameter, right_diameter;
        int current_diameter;

        int best = 0;

        if(root == nullptr)
            return 0;

        if(root->left == nullptr)
            left_diameter = 0;
        else
            left_diameter = check_level(root->left) + 1;
        
        if(root->right == nullptr)
            right_diameter = 0;
        else
            right_diameter = check_level(root->right) + 1;

        current_diameter = left_diameter + right_diameter;
            
        int left_best, right_best;

        left_best = diameterOfBinaryTree(root->left);
        right_best = diameterOfBinaryTree(root->right);

        if(left_best > right_best)
            best = left_best;
        else
            best = right_best;

        if(best > current_diameter)
            return best;
        else
            return current_diameter;
    }

    int check_level(TreeNode* root) {
        if(root == nullptr)
            return 0;

        if(root->left == nullptr && root->right == nullptr)
            return 0;
        
        if(root->left == nullptr)
            return check_level(root->right) + 1;
        if(root->right == nullptr)
            return check_level(root->left) + 1;

        int left_level, right_level;

        left_level = check_level(root->left);
        right_level = check_level(root->right);

        if(left_level > right_level)
            return left_level + 1;
        else
            return right_level + 1;
    }
};