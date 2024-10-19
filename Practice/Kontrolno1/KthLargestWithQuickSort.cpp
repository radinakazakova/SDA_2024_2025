//quick sort method
//другия вариант е със sort и търсим k-тия

/*   int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size() -k];
    }
*/

class Solution {
public:
    int partition(vector<int>& nums, int left, int right)
    {
        int pivot = nums[right];
        int l = left;

        for(int i = left; i < right; i++)
        {
            if(nums[i] < pivot)
            {
                swap(nums[l], nums[i]);
                l++;
            }
        }
        swap(nums[l], nums[right]);
        return l;
    }
    int quickSort(vector<int>& nums, int left, int right, int k)
    {   
        if(left > right)
            return 0; //nz

        if(left == right)
            return nums[left];
            
        int pivotIdx = partition(nums, left, right);
        if(pivotIdx == nums.size() - k) //ako indexa е равен на пивот индекса значи сме намерили елемента
        {
            return nums[pivotIdx];
        }
        else if(pivotIdx > nums.size() - k) //ако пивота е по-голям от това което търсим, обхождаме лявата част (търсим по-малък индекс)
        {
            return quickSort(nums, left, pivotIdx - 1, k);

        }
        else
            return quickSort(nums, pivotIdx + 1, right, k); //ако е по-малък, дясната част обхождаме
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() -1;

        return quickSort(nums, left, right, k);
    }
};
