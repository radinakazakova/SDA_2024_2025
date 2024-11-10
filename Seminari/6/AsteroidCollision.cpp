class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> passing;
        int size = asteroids.size();
        for(int i = 0; i < size; i++)
        {
            if(passing.empty()){
                passing.push_back(asteroids[i]);
                continue;
            }
            if(passing.back() < 0 || (passing.back() > 0 && asteroids[i] > 0))
            {
                passing.push_back(asteroids[i]);
                continue;
            }
            if(passing.back() > 0 && asteroids[i] < 0)
            {
                while(!passing.empty() && abs(passing.back()) < abs(asteroids[i]) && passing.back() > 0)
                    passing.pop_back();
                if(!passing.empty() && passing.back() == abs(asteroids[i])){
                    passing.pop_back();
                    continue;
                }
                if(passing.empty() || passing.back() < 0)
                    passing.push_back(asteroids[i]);
            }
        }
        
        return passing;
    }
};
