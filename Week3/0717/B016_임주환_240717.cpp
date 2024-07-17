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
    TreeNode* increasingBST(TreeNode* root) {
        deque<int> values;
        
        checkValues(root, &values);

        return makeBST(values);
    }

    void checkValues(TreeNode* root, deque<int>* values) {
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr)
        {
            (*values).push_back(root->val);
            return;
        }

        if(root->left != nullptr)
            checkValues(root->left, values);
        
        (*values).push_back(root->val);

        if(root->right != nullptr)
            checkValues(root->right, values);
    }

    TreeNode* makeBST(deque<int> v) {

        if(v.size() == 0)
            return nullptr;

        TreeNode* root = new TreeNode(v.front());
        v.pop_front();

        root->right = makeBST(v);

        return root;
    }
};