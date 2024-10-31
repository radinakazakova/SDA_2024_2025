//моето решение с намиране на размера и reverse на първата половина от списъка
//O(n) time, O(1) space
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
    bool isPalindrome(ListNode* head) {
        if(!head)
            return false;
        if(!head->next)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 1;
        int size = 0;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast == nullptr)
            size = count * 2;
        else
            size = count* 2 - 1;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != slow)
        {
            ListNode* next = curr->next; //пазим следващия, защото на следващия ред го губим
            curr->next = prev;
            prev = curr; // местим напред
            curr = next; // местим напред
        }
        
        curr = prev;

        if(size % 2) //ако размерът е нечетен (case, в който средния елемент не е от значение)
            slow = slow->next;
   
        while(curr && slow)
        {
            if(curr->val != slow->val)
                return false;
            slow = slow->next;
            curr = curr->next;
        }
        return true;
    }
};
