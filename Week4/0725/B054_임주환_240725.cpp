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
    vector<int> preorder(Node* root) {
        vector<int> answer;

        if(root == nullptr)
            return answer;

        answer.push_back(root->val);

        int c_size = root->children.size();

        for(int i = 0 ; i < c_size ; i++)
        {
            vector<int> tmp = preorder(root->children[i]);
            answer.insert(answer.end(), tmp.begin(), tmp.end());
        }

        return answer;
    }
};