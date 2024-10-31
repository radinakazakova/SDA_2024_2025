//решение с 2 указателя

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr) //1 element
            return nullptr;

        //няма да използваме fast да прескача през едно, а както се движи slow
        ListNode* slow = head; 
        ListNode* fast = head;
        for(int i = 0; i < n; i++) //искаме да създадем разстояние = n между двата указателя
        {   
            fast = fast->next;
        }

        if(!fast) //ако е стигнал края, да махнем първия
        {
            return head->next;
        }

        while(fast->next) //така, че slow да застане на мястото на previous
        {
            slow = slow->next;
            fast = fast->next;
        }

       slow->next = slow->next->next;
       return head;
    }
};
