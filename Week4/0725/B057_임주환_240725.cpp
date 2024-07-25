/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr)
            return 0;

        int max = 0;
        int c_size = root->children.size();

        for(int i = 0 ; i < c_size ; i++)
        {
            int tmp = maxDepth(root->children[i]);
            if(max < tmp)
                max = tmp;
        }
        max++;

        return max;
    }
};