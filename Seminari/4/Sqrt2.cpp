class Solution {
public:
    int mySqrt(int x) {
       if(x==1 || x == 0)
            return x;
        long int start = 1;
        long int mid = 0;
        long int end = x;
        while(end>=start){
            mid = (start +end)/2;
            if(mid*mid > static_cast<long>(x))   
                end = mid-1;
            else if (mid*mid == static_cast<long>(x))
                return mid;
            else
                start = mid+1;
        }
    return int(end);
    }
};
