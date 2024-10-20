//O(n*logn)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int target = 1; //ignorirame negative nums
        for (int n : nums) {
            if (n > 0 && n == target) { //ima li positive poredno, ako ima 'target++' - tursim sledvashtoto
                target++;
            } else if (n > target) {
                return target;
            }
        }

        return target;
    }
};
