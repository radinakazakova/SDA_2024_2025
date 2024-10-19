class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      
        vector<int> intersection;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int size1 = nums1.size();
        int size2 = nums2.size();

        int first =0;
        int second =0;

        while(first < size1 && second < size2)
        {
            if(nums1[first] == nums2[second])
            {
                intersection.push_back(nums1[first++]);
                second++;
            }
            else if(nums1[first] < nums2[second])
            {
                first++;
            }else
            {
                second++;
            }
        }
        return intersection;
    }
};
