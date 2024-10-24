class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int len = arr.size();
        int left = 0;
        int right = len - 1;
        while(left < right) //без равното, последното им състояние е когато са на един и същ индекс
        {
            int mid1 = left + (right - left)/3;
            int mid2 = right - (right -left)/3;

            if(arr[mid1] < arr[mid2]) 
            {
                left = mid1 + 1;
            }else //равното влиза тук, местим се наляво 
            {
                right = mid2 - 1; //ако сме в кейса в който има равенство right се разминава с left и left остава на правилната позиция
            }
        }
        return left;
    }
};

//съответно и този код работи по същата причина
/* class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int len = arr.size();
        int left = 0;
        int right = len - 1;
        while(left < right)
        {
            int mid1 = left + (right - left)/3;
            int mid2 = right - (right -left)/3;

            if(arr[mid1] > arr[mid2])
            {
                right = mid2 - 1;
            }else
            {
                left = mid1 + 1;
            }
        }
        return right;
    }
};
*/
