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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* iter = head;
        while(iter)
        {
            ListNode* curr = iter; //pazim purvoto sreshtane na val
            while(iter && iter->val == curr->val)
                iter = iter->next; //nakraq iter shte e na purvoto razlichno chislo
            curr->next = iter;
        }
        return head;
    }
};
