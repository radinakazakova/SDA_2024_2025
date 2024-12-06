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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* node1, const ListNode* node2)
        {
            return node1->val > node2->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq; //minHeap s Node*

        for(size_t i = 0; i < lists.size(); i++) {
            if(lists[i]) //dobavqme purviq element na vseki
                pq.push(lists[i]);
        }

        if(pq.empty())
            return nullptr;

        ListNode* headNode = pq.top(); //знаем как да определим head
        ListNode* iter = headNode;
        //преди да попнем трябва да добавим следващия елемент в heap-a, ако има такъв
        if(headNode->next)
            pq.push(headNode->next);

        pq.pop();
        //за всеки текущ елемент следващия ще бъде top на pq ( следващия най-малък )
        while(!pq.empty())
        {
            iter->next = pq.top();
            iter = iter->next; //iter = pq.top() -> mojem da popnem
            pq.pop();
            if(iter->next)
                pq.push(iter->next);
        }

        return headNode;
    }
};
