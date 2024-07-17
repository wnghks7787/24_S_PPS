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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool answer;

        if(root == nullptr)
            return false;

        if(root->val == targetSum)
        {
            if(root->left == nullptr && root->right == nullptr)
                return true;
        }

        if(root->left != nullptr)
            answer = hasPathSum(root->left, targetSum - root->val);

        if(answer)
            return answer;

        if(root->right != nullptr)
            answer = hasPathSum(root->right, targetSum - root->val);
        
        if(answer)
            return answer;

        return false;
    }
};