//изполва longest increasing subsequence за height на пислата
class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        // Sort envelopes by width in ascending order. 
        // If two envelopes have the same width, sort by height in descending order.
        std::sort(envelopes.begin(), envelopes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        // Extract the heights into a separate list.
        std::vector<int> heights;
        for (const auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }

        // The 'ans' vector will store the increasing subsequence of heights.
        std::vector<int> ans;

        for (const int height : heights) {
            // Find the position where 'height' can be placed in 'ans' using binary search.
            auto it = std::lower_bound(ans.begin(), ans.end(), height);

            // If 'height' is greater than all elements in 'ans', append it.
            if (it == ans.end()) {
                ans.push_back(height);
            } 
            // Otherwise, replace the element at the found position with 'height'.
            else {
                *it = height;
            }
        }

        // The size of 'ans' represents the length of the longest increasing subsequence.
        return ans.size();
    }
};
