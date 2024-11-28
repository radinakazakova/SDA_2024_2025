class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // key - sum
        // val - first occurence of that sum
        unordered_map<int, int> c;
        c[0] = -1; // sum was zero before the start of traversal
        int sum = 0;
        int maxLength = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1 ? 1 : -1); //всяка нула я приемаме за -1, за да се възползваме от това, че като срещнем дадена сума повторно означава, че ще имаме еднакъв брой 1 и 0
            auto iter = c.find(sum);
            if(iter != c.end()) {
                maxLength = max(maxLength, i - iter->second); 
            }
            else {
                c[sum] = i; //пазим на кой индекс се е намирала сумата за първи път
            }
        }
        return maxLength;
    }
};
