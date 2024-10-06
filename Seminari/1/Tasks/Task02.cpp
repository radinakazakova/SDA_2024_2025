class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {
        unsigned size = digits.size();

        for(int i = size - 1; i >= 0; i--)
        {
            if(i == 0 && digits[i] == 9)
            {
                digits[i] = 1;
                digits.push_back(0);
            }
            else if(digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                ++digits[i];
                break;
            }
        }
        return digits;
    }
};
