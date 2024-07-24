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
    int findTilt(TreeNode* root) {
        if(root == nullptr)
            return 0;

        if(root->left == nullptr && root->right == nullptr)
            return 0;

        int answer = 0;

        if(root->left == nullptr)
        {
            answer += findTilt(root->right);
            answer += abs(sumOfAllSubTrees(root->right), 0);

            return answer;
        }
        if(root->right == nullptr)
        {
            answer += findTilt(root->left);
            answer += abs(sumOfAllSubTrees(root->left), 0);

            return answer;
        }

        return findTilt(root->left) + findTilt(root->right) + abs(sumOfAllSubTrees(root->left), sumOfAllSubTrees(root->right));
    }

    int sumOfAllSubTrees(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        if(root->left == nullptr && root->right == nullptr)
            return root->val;
        if(root->left == nullptr)
            return root->val + sumOfAllSubTrees(root->right);
        if(root->right == nullptr)
            return root->val + sumOfAllSubTrees(root->left);

        return root->val + sumOfAllSubTrees(root->left) + sumOfAllSubTrees(root->right);
    }

    int abs(int a, int b) {
        return a > b ? a-b : b-a;
    }
};