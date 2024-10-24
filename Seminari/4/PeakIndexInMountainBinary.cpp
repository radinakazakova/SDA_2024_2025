class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1;
        int r = arr.size() - 2;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) { //предходния и следващия са по-малки от мид, намерихме го
                return mid;
            }
            else if(arr[mid] > arr[mid - 1]) { //нараства, значи надясно
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
            
        }
        
        return -1;
    }
};
