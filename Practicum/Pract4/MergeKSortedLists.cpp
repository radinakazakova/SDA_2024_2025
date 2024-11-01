//решение, което използва Merge на два листа, което сме писали на семинар
//рекурсивно ги сортираме 2 по 2
//или ако остане едно го връщаме, зашото само по себе си е сортирано

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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;

        if (l1->val > l2->val) { //za da moje list1 da e po-malkiq
            swap(l1, l2); //podredbata se opredelq tuk
        }

        //rabotim napravo v list1 bez result
        l1->next = merge(l1->next, l2);
        return l1;        
    }

    ListNode* mergeSortLists(vector<ListNode*>& lists, int left, int right) //сортиране на листите поотделно
    {
        if(left == right) //дъно, ако left и right съвпаднат
        {
            return lists[left];
        }

        if(left + 1 == right)
        {
            return merge(lists[left], lists[right]);
        }

        int mid = left + (right - left)/2; //binary по масива
        ListNode* leftSide = mergeSortLists(lists, left, mid); //след рекурсията тук ще са сортирани едната половина от списъците
        ListNode* rightSide = mergeSortLists(lists, mid+1, right);

        return merge(leftSide, rightSide); //сортираме и двете половини заедно
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();

        if(size == 0)
            return nullptr;
        
        return mergeSortLists(lists, 0, size - 1);
    }
};
