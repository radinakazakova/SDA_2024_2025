//да се съобрази, че при отрицателни числа може да получим по-голямо число отпред, като умножим 2 отрицателни и после с последното
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();

        int negative = nums[0]*nums[1] * nums[len -1];
        int positive = nums[len - 1] * nums[len -2 ]* nums[len - 3];

        return max(negative, positive);
    }
};
