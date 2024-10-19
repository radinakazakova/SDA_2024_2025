//s indeksaciq

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(n+m);

        int first = 0;
        int second = 0;
        int r = 0;

        while( first < m && second < n)
        {
            if(nums1[first] <= nums2[second])
            {
                res[r++] = nums1[first++];
            }else
            {
                res[r++] = nums2[second++];
            }
        }

        while(first < m)
        {
            res[r++] = nums1[first++];
        }
        while(second < n)
        {
           res[r++] = nums2[second++]; 
        }

        for(int i = 0; i < n+m; i++)
        {
            nums1[i] = res[i];
        }
    }
};
