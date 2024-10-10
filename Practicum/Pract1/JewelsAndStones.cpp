class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        int jewelsLen = jewels.size();
        int stonesLen = stones.size();

        for(int i = 0; i < jewelsLen; i++)
        {
            for(int j = 0; j < stonesLen; j++)
            {
                if(jewels[i] == stones[j])
                {
                    count++;
                } 
            }
        }
        return count;
    }
};
