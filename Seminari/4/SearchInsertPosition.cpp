class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target)
                return mid;

            else if(nums[mid] > target)
                right = mid -1;
            else
                left = mid + 1;
        }
        return left; //ако го няма, пази позицията му, защото на последната стъпка в цикъла когато left = right, left и right ще се разминат
    }
    //винаги left ще остане на позицията на x, позицията, на която има число по-голямо от x, а right ще е на мястото на числото по-малко от x
};
