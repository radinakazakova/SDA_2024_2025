//директно работим със списъка

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) 
            return head;
        
        ListNode* dummy = new ListNode(0); //node kojto sochi kum lista ni
        
        dummy->next = head;
        ListNode* curr = head->next;
        ListNode* lastSorted = head;
        
        while (curr != nullptr) {
            if (lastSorted->val <= curr->val) { //в случай, че са наредени
                // If current node is greater than last sorted, just move forward
                lastSorted = curr;
            } else { //намерен е по-малък
                // всеки път като намерим по-малък почваме от началото и търсим мястото му
                ListNode* prev = dummy;
                
                while (prev->next->val <= curr->val) { //curr e намереното по-малко,докато е наредено продължаваме напред и държим предходното в prev
                    prev = prev->next;
                }//prev-позицията, на която да сложим curr
                
                lastSorted->next = curr->next; //последния сортиран да прескочи този, който местим
                curr->next = prev->next; //този, който нареждаме да сочи натам, защото позицията му е prev
                prev->next = curr; //преместваме да сочи към числото, което наместихме току-що
            }
            curr = lastSorted->next; //преминаваме към следващото число за нареждане
        }
        
        ListNode* result = dummy->next;
        return result;
    }
};
