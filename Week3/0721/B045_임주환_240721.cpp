/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    vector<int> lists;
public:
    bool isPalindrome(ListNode* head) {
        traversal(head);

        int l_size = lists.size();

        for(int i = 0 ; i < l_size / 2 ; i++)
        {
            if(lists[i] != lists[l_size - i - 1])
            {
                return false;
            }
        }

        return true;
    }

    void traversal(ListNode* head) {
        if(head == nullptr)
            return;
        
        lists.push_back(head->val);
        traversal(head->next);
    }
};