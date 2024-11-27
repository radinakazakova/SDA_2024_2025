class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long size = nums.size();
        long long allPairs = (size * (size - 1)) / 2;
        long long goodPairs = 0;
       //ako izpolzvam indeksi kato key
        unordered_map<int, long long> map;
        //tursim nums[j], za koeto j - i == nums[j] - nums[i]
        //nums[j] - j == nums[i] - i
        //target = nums[j] - j, target == nums[i] - i
        for(int j = 0; j < size; j++)
        {
            int target = nums[j] - j; //tova ni e key, zashtoto ako target = nums[i] - i tova znachi che shte dodavqme v map-a za tazi opredelena stoinost, kolko goodPairs ima za tazi dadena stoinost
            if(map.count(target)) //ako ima 1 - toest v tekushtoto sustoqnie imame 2 demek sa pair
            {
                goodPairs += map[target]; // za target kolko do sega good pairs ima
            }
            map[target] += 1;
        }

        return allPairs - goodPairs;
    }
};
