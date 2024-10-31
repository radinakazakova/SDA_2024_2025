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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return nullptr;
        if(!head->next)
            return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;
        while(even && even->next) //even->next e проверка за odd
        {
            odd->next = odd->next->next;
            odd = odd->next;

            even->next = even->next->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};
