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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        
        ListNode* iter = head;
        ListNode* prev = nullptr;
        while(iter)
        {
            if(iter == head && iter->val == val)
            {
                head = iter->next;
                prev = nullptr;
                iter = head;
                continue;
            }
            else if(iter->val == val)
            {
                prev->next = iter->next;
                iter = iter->next;
                continue;
            }

            prev = iter;
            iter = iter->next;
        }
        return head;
    }
};
