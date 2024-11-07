//със stack, защото се интересуваме какво е било последно добавено, ако всичко е наред искаме да го махнем също
class Solution {
public:
    bool isOpen(char ch)
    {
        return ch == '(' || ch == '{' || ch == '[';
    }
    bool isReversed(char l, char r) {
        return (l == '(' && r == ')')
            || (l == '{' && r == '}')
            || (l == '[' && r == ']');
    }

    bool isValid(string s) {
        stack<char> brackets;

        for(auto ch: s)
        {
            if(isOpen(ch))
            {
                brackets.push(ch);
            }
            else
            {
                if(brackets.empty() || !isReversed(brackets.top(), ch))
                {
                    return false;
                }

                brackets.pop();
            }
        }
        return brackets.size() == 0;
    }
};
