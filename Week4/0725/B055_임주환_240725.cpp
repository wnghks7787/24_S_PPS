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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> answer1 = findLeaf(root1);
        vector<int> answer2 = findLeaf(root2);

        int size1 = answer1.size();
        int size2 = answer2.size();

        if(size1 != size2)
            return false;

        for(int i = 0 ;  i < size1 ; i++)
        {
            if(answer1[i] != answer2[i])
                return false;
        }
        return true;
    }

    vector<int> findLeaf(TreeNode* root) {
        vector<int> answer;

        if(root == nullptr)
            return answer;

        if(root->left == nullptr && root->right == nullptr)
        {
            answer.push_back(root->val);
            return answer;
        }

        if(root->left != nullptr)
        {
            vector<int> tmp = findLeaf(root->left);
            answer.insert(answer.end(), tmp.begin(), tmp.end());
        }

        if(root->right != nullptr)
        {
            vector<int> tmp = findLeaf(root->right);
            answer.insert(answer.end(), tmp.begin(), tmp.end());
        }

        return answer;
    }
};