class Solution {
public:

    bool hasH(vector<int>& citations, int h)
    {
        auto lower = std::lower_bound(citations.begin(), citations.end(), h) - citations.begin();
        int upper = citations.size();
        return (upper - lower) >= h;
    }
    int hIndex(vector<int>& citations) {
        int maxH = citations.size();
        int minH = 1;
        int currMaxH = 0;
        
        while(minH <= maxH)
        {
            int mid = minH + (maxH  - minH)/2;
            if(hasH(citations, mid))
            {
                minH = mid + 1;
                currMaxH = mid;
            }else
                maxH = mid - 1;
        }
        return currMaxH;
    }
};
