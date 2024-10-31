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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* iterA = headA; // | headA дo Intersection | = a 
        ListNode* iterB = headB; // | headB до Intersection | = b
      
        //iterA извървява 'а', после |intersection|, после 'b'
        //iterB извървява 'b', после |intersection|, после 'a'
        //така пътищата им се изравняват точно в точката на пресичане

        while(iterA != iterB)
        {
            if(!iterA)//стига края и го местим в началото на другия
                iterA = headB;
            else
                 iterA = iterA->next;

            if(!iterB)//аналог., разликата между двете да се изравни
                iterB = headA;
            else
                iterB = iterB->next;
        }

        return iterA;
    }
};
