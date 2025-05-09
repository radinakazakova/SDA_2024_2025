class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int result = x;

        while(left <= right)
        {
            long mid = left + (right - left)/2;

            if(mid*mid > x)
                right = mid - 1;
            else{
                result = mid; //намери ли сме най-близкия отговор
                left = mid + 1;
            }
        }
        return result;
    }
};
