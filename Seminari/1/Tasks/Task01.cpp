#include <iostream>
#include <vector>
using namespace std;

/*
 * LeetCode contest: https://leetcode.com/problems/move-zeroes/description/
 * 
 idx променя подред в масива с всеки нов намерен ненулев елемент 
 втория цикъл занулява всичко след преместените ненулеви елементи
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int idxChanges = 0;

        for (int i = 0; i < nums.size(); ++i) {
          
            if (nums[i] != 0){
                nums[idxChanges++] = nums[i];
            }
        }

        for (int i = idxChanges; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    
    }
};
