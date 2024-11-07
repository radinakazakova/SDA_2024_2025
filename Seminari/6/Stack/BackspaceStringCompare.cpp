class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> first;
        stack<char> second;

        //първо да махнем # за всеки стринг по отделно
        for(auto f: s)
        {
            if(f == '#')
            {
                if(!first.empty())
                    first.pop();
            }
            else
                first.push(f);
        }

        
        for(auto sec: t)
        {
            if(sec == '#')
            {
                if(!second.empty())
                    second.pop();
            }
            else
                second.push(sec);
        }
         //различен размер - със сигурност не са еднакви
        if(first.size() != second.size())
            return false;
        
        while(!first.empty())
        {
            if(first.top() != second.top())
                return false;
             //ако са равни елементите ги махаме
            first.pop();
            second.pop();
        }
        return true;
    }
};
