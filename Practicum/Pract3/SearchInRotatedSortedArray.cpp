// 2 случая, които обсъдихме на практикума
//1. Мин/макс разцепването е от дясната страна на mid - тоест лявата страна е сортирана
//2. Мин/макс разцепването е от лявата страна на mid - тоест дясната страна е сортирана
// left > mid => mid e в ляво - rightside sorted
// left <= mid => mid e в дясно - leftside sorted
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(nums[mid]==target)
                return mid;
            
            if(nums[left] <= nums[mid]) //left side sorted
            {
                if(target < nums[mid] && target >= nums[left]) //sorted part
                {
                    right = mid - 1;
                }
                else //unsorted part
                {
                    left = mid + 1;
                }
            }
            else //right side is sorted
            {
                if(target > nums[mid] && target <= nums[right]) //sorted part
                {
                    left = mid + 1;
                }
                else //unsorted part
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
