#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode* left, TreeNode *right);

    void updateNode(TreeNode* node);
};

void readNode(TreeNode* root);

using namespace std;

int main()
{
    // TreeNode* root1 = new TreeNode(5);
    // TreeNode* root2 = new TreeNode(3);
    // TreeNode* root3 = new TreeNode(1, root1, root2);

    // cout << root3->val << endl;
    // cout << root3->left->val << endl;
    // cout << root3->right->val << endl;

    TreeNode* root = new TreeNode();
    int t;

    while(cin >> t)
    {

        if(root->val == 0)
        {
            root->val = t;
            continue;
        }
        
        root->updateNode(new TreeNode(t));
    }

    readNode(root);

    return 0;
}

TreeNode::TreeNode()
{
    val = 0;
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(int x)
{
    val = x;
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(int x, TreeNode* left, TreeNode* right)
{
    val = x;
    this->left = left;
    this->right = right;
}

void TreeNode::updateNode(TreeNode* node)
{
    if(this->val > node->val)
    {
        if(this->left == nullptr)
            this->left = node;
        else
            this->left->updateNode(node);
    }
    else
    {
        if(this->right == nullptr)
            this->right = node;
        else
            this->right->updateNode(node);
    }
}

void readNode(TreeNode* root)
{
    if(root->left != nullptr)
        readNode(root->left);

    if(root->right != nullptr)
        readNode(root->right);

    cout << root->val << endl;
}