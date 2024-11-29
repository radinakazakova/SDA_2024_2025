//бил съм умен сетил съм се
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int size = rolls.size();
        unordered_set<int> s;
        int res = 1;
        for(int i = 0; i < size; i++)
        {   
            s.insert(rolls[i]);
            if(s.size() == k)
            {
                res++;
                s.clear();
            }
        }
        return res;
    }
};
