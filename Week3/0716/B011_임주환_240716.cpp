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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root = new TreeNode();

        if(root1 != nullptr && root2 != nullptr)
        {
            root->val = root1->val + root2->val;

            // deal with left
            if(root1->left != nullptr && root2->left != nullptr)
                root->left = mergeTrees(root1->left, root2->left);
            else if(root1->left == nullptr && root2->left != nullptr)
                root->left = root2->left;
            else if(root1->left != nullptr && root2->left == nullptr)
                root->left = root1->left;

            // deal with right
            if(root1->right != nullptr && root2->right != nullptr)
                root->right = mergeTrees(root1->right, root2->right);
            else if(root1->right == nullptr && root2->right != nullptr)
                root->right = root2->right;
            else if(root1->right != nullptr && root2->right == nullptr)
                root->right = root1->right;
        }
        else if(root1 == nullptr && root2 != nullptr)
            root = root2;
        else if(root1 != nullptr && root2 == nullptr)
            root = root1;
        else
            root = nullptr;
        
        return root;
    }
};