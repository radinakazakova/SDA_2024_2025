class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        //key e candyType[i]

        int size = candyType.size();
        int candiesToEat = size/2;
        int candies = 0;
        unordered_map<int,int> map;
        for ( int i = 0; i < size && candiesToEat; i++)
        {
            if(map.count(candyType[i]))
            {
                continue;
            }
            map[candyType[i]] = 1;
            candiesToEat--;
            candies++;
        }
        return candies;
    }
};
