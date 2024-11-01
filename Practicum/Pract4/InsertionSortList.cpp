//Решение с допълнителна памет, върху която прилагаме insertion sort
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* iter = head;
        vector<int> nums;
        while(iter)
        {   
          nums.push_back(iter->val);
          iter = iter->next;
        }

        for(int i = 1; i < nums.size(); i++)
        {
            int element = nums[i];
            int index = i - 1;
            while(index>=0 && nums[index]>element)
            {
                nums[index+1] = nums[index];
                index--;
            }
            nums[index+1] = element;
        }

        iter = head;
        for(int i = 0; i < nums.size(); i++)
        {
            iter->val = nums[i];
            iter = iter->next;
        }
        return head;
    }
};
