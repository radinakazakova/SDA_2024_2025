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
    void deleteNode(ListNode* node) { //най-важният детайл е, че всички vals са unique (?)
        node->val = node->next->val; //приемаме стойността на следващия node и го скипваме след това
        node->next = node->next->next; //знаем,че не сме в tail
    }
};
