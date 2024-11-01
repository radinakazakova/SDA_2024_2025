//може да се използва направо и fast вместо meeting
//вътре в цикъла още един while и връща отг., ако излезе връща nullptr
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* meeting = nullptr;

        while(fast && slow && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast)
            {
                meeting = slow;
                break;
            }
        }

        if(!meeting)
            return nullptr;
        
        slow = head;

        while(slow != meeting)
        {
            slow = slow->next;
            meeting = meeting->next;
        }
        return slow;
    }
};
