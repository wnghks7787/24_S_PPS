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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;

        if(list1->val > list2->val)
        {
            ListNode* tmp = list1;
            list1 = list2;
            list2 = tmp;
        }
        ListNode* traversal = list1;
        while(1)
        {
            if(list2 == nullptr)
                break;

            if(traversal == nullptr)
            {
                list1 = list2;
                break;
            }

            if(traversal->next == nullptr)
            {
                traversal->next = list2;
                break;
            }

            if(traversal->next->val > list2->val)
            {
                ListNode* tmp = new ListNode(list2->val, traversal->next);
                traversal->next = tmp;
                list2 = list2->next;
                continue;
            }
            traversal = traversal->next;
        }

        return list1;
    }
};