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
     size_t len(ListNode* node) {
        size_t length = 0;
        while(node) {
            node = node->next;
            length++;
        }
        return length;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        size_t size = len(head);
        vector<int> res(size, 0);
        stack<int> index, value; //value ще е в намаляващ ред - ако намерим по-голямо попваме всички по-малки и записваме head->val

        size_t counter = 0;

        while(head)
        {
            while(!value.empty() && value.top() < head->val) //намираме по-голям елемент от текущия
            {
                res[index.top()] = head->val; //за съответния индекс добавяме новото по-голямо
                index.pop(); //махаме ги - намерихме резултат
                value.pop();
            }

            index.push(counter);
            value.push(head->val);
            counter++;
            head = head->next;
        }
        return res;
    }
};
