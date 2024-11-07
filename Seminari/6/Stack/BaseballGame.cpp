class Solution {
public:
    bool isSpecial(string& ch)
    {
        return ch == "+" ||
               ch == "D" ||
               ch == "C";
    }
    int calPoints(vector<string>& operations) {
        stack<int> scores;

        for(auto& o: operations)
        {
            if(isSpecial(o))
            {
                if( o == "+")
                {
                    int top = scores.top();
                    scores.pop();
                    int secToLast = scores.top();
                    int sum = top + secToLast;
                    scores.push(top);
                    scores.push(sum);
                }
                else if(o == "C")
                {
                    scores.pop();
                }
                else if(o == "D")
                {
                    scores.push(2* scores.top());
                }
            }
            else
            {
                scores.push(stoi(o));
            }
        }
        int allSum = 0;
        while(!scores.empty())
        {
            int toAdd = scores.top();
            allSum += toAdd;
            scores.pop();
        }
        return allSum;
    }
};
