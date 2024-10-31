//рекурсивно

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { //list1 i list2 izpolzvame kato iteratori
        if(!list1)
            return list2;
        if(!list2)
            return list1;

        if (list1->val > list2->val) { //za da moje list1 da e po-malkiq
            swap(list1, list2); //podredbata se opredelq tuk
        }

        //rabotim napravo v list1 bez result
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;        
    }
};
