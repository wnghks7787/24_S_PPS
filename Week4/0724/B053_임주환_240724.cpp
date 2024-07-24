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
    vector<int> postorder(Node* root) {
        vector<int> answer;
        if(root == nullptr)
            return answer;

        int c_size = root->children.size();
        
        if(c_size == 0)
        {
            answer.push_back(root->val);
            return answer;
        }

        for(int i = c_size-1 ; i >= 0 ; i--)
        {
            vector<int> t = postorder(root->children[i]);
            answer.insert(answer.begin(), t.begin(), t.end());
        }
        answer.push_back(root->val);

        return answer;
    }
};