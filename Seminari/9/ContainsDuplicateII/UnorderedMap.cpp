class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> map; //valueto da e indeksa

        for(int i = 0; i< nums.size(); i++)
        {//count - kolko elementa ima s nums[i] kluch
            if(map.count(nums[i]) > 0 && map[nums[i]] >= i - k) // i - j <= k -> - j <= k - i  (po -1) -> j >= i - k //v sluchaq 'i' ni e tekushtiq element - po-golqm indeks ot predniq koito e 'j' i e value na dobaveniq element s koito sravnqwame
            {
                return true;
            }

            map[nums[i]] = i; //dobavqme kluch nums[i] sus stojnost i
        }

        return false;
    }
};
