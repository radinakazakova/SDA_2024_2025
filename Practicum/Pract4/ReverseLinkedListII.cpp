//по картинки го измислих
//пазим node-a преди left и node-a след right, за да ги нагласим след reverse-ването
//като в началото prev e този след right, за да може първия в reverse да се закачи към края
//ще обръщаме още от head - head ще се промени на prev след reverse-ването (prev e последния node, който сме насочили наобратно)
//във всички други случаи head се запазва

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right) //празен или ще reverse-ваме 1 елемент
            return head;

        ListNode* leftPtr = head;
        ListNode* beforeLeft = nullptr;
        while(left - 1)
        {
            beforeLeft = leftPtr;
            leftPtr = leftPtr->next;
            left--;
        }

        ListNode* afterRight = head;
        while(right)
        {
            afterRight = afterRight->next;
            right--;
        }

        ListNode* prev = afterRight;
        while(leftPtr != afterRight)
        {
            ListNode* next = leftPtr->next;
            leftPtr->next = prev;
            prev = leftPtr;
            leftPtr = next;
        }
        
        if(!beforeLeft) //left == 1
            return prev;
        
        beforeLeft->next = prev; //left ne e v nachaloto
        return head;
    }
};
