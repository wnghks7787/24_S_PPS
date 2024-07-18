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
public:
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* traversal = head;
        while(1)
        {
            if(traversal == nullptr)
                break;

            traversal = traversal->next;
            size++;
        }

        int middle = size / 2;

        for(int i = 0 ; i < middle ; i++)
            head = head->next;

        return head;
    }
};