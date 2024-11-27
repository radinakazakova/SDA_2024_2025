class Solution {
public:
    string getBinaryString(int num, int len) { //превръщане на число в binary string
        string binaryString = "";
        for (int i = len - 1; i >= 0; --i) {
            binaryString += ((num & (1 << i)) ? '1' : '0');
        }
        return binaryString;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int len = nums.size(); 
        set<string> s(nums.begin(), nums.end()); // Store all input strings in a set

        // Check all possible n-bit binary strings
        //обикаляме само възможностите сред числата със същата дължина в binary 
        for (int i = 0; i < (1 << len); ++i) {
            string candidate = getBinaryString(i, len);
            if (s.find(candidate) == s.end()) { //ако числото го няма връщаме стринга
                return candidate; 
            }
        }

        return "";
    }
};
