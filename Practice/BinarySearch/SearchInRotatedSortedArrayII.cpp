//с дупликати
class Solution {
public:
    bool binarySearch(vector<int>& nums, int target, int left, int right)
    {
        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(nums[mid] == target)
                return true;

            if(nums[mid] == nums[left] && nums[mid] == nums[right]) //работ, защото ни пречат само когато са от двете страни. ако left==mid, то и right==mid,заради ротацията
            {
                left++;
                right--;
                continue;
            }
            
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
        return false;
    }

    bool search(vector<int>& nums, int target) {
       return binarySearch(nums, target, 0, nums.size() - 1);
    }
};
