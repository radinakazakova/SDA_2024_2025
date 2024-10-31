//итеративно
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

        ListNode* head = nullptr;
        ListNode* result = nullptr;

        if(list1->val < list2->val) //za da opredelim head na noviq spisuk
        {
            head = result = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            head = result = new ListNode(list2->val);
            list2 = list2->next;
        }

        while(list1 && list2)
        {
            if(list1->val < list2->val){
                result->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                result->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            result = result->next;
        }

        if(list1){ //ako ima ostanalo ot list1 nasochvame se kum nego napravo
            result->next = list1;
        } else if(list2){ //analogichno
            result->next = list2;
        }
        return head;
    }
};
