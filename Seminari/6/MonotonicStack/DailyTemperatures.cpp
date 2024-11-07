class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> res(size, 0);

        stack<int> index;
        int counter = 0;

        //ще работим само с инкесите i 
        for(int i = 0; i < size; i++)
        {
            while(!index.empty() && temperatures[index.top()] < temperatures[i])
            {
                res[index.top()] = i - index.top();
                index.pop();
            }
            index.push(i);
        }
        return res;
    }
};
