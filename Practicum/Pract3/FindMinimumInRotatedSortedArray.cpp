//заради възможността от дупликати се изисква да използваме рекурсия
//без дупликати кодът ще изглежда така:
/* class Solution {
public:
    int findMin(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int left = 0, right = nums.size() - 1;

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[right]; //тук няма значение дали ще върнем left или right, защото цикълът приключва, когато са равни
    }
};
*/

class Solution {
public:

    int binarySearch(vector<int>& nums, int left, int right) {
        while(true) //ако сравняваме с left не работи (if-ове)
        {
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]) //не може да е mid - защото е по-малко от right
            {
                left = mid + 1;
                continue;
            }
            
            //работи така, че min евентуално да остане на индекса right
            if (nums[mid] < nums[right]){ // Minimum is either at mid or in the left half - тук може да е mid
                right = mid; // So no '- 1'
                continue;
            }

            if(nums[mid] == nums[right] && left != right) //за дупликати, пример: [1,3,3]
            { 
                int leftSearchValue = binarySearch(nums, left, mid);
                if (leftSearchValue != nums[mid]) {
                    // If a different value is found in the left half, return it
                    return leftSearchValue;
                }
                // Otherwise, search the right half
                return binarySearch(nums, mid + 1, right); //заради примери като: [3, 3, 1, 3]
            }

            // Base case: If we have reduced the range to a single element, return it as the minimum
            return nums[mid];
        }
    }
     int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
     }
};
