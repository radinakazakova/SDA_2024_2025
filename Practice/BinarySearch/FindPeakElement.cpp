class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right)
    {
        int size = nums.size();
        while(left < right)
        {
            int mid = left + (right - left)/2;

            if((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == size - 1 || nums[mid] > nums[mid + 1])) //mid == 0, mid == size - 1 са важни за проверката по-краищата
                return mid;
            
            //работи, тъй като дори и да са сортирани надясно/наляво крайният елемент ще е връх примерно [1,2,1,3,5,6,7] - 7 is peak ще върне функцията
            //и тъй като няма повторения, ако преминаваме към по-голямото число със сигурност ще намерим връх
            if(mid < size - 1 && nums[mid + 1] > nums[mid]) //ако вдясно е по-голям отиваме надясно, защото може да е peak
            {
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return left; //left == right
    }

    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size()-1); //никои две числа едно до друго не са равни
    }
};
