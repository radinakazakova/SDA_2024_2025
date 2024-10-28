class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res; //ще пазим последователността тук

        for (int n : nums) {
            if (res.empty() || res.back() < n) { //ако елемент е по-голям, го добавяме накрая
                res.push_back(n);
            } else {
                int idx = binarySearch(res, n); //ако е по-малко, искаме да го сложим, търсим индекса, на който трябва да се намира, в най-лошия случай ще го сложим на мястото на друг елемент, който вече е изпълнявал правилно последователността
               //но сме оптимизирали така, че да добавим по-малките числа, за да пресмятаме правилно (ако са накрая)
                res[idx] = n;
            }
        }

        return res.size();        
    }

private: //смятаме позицията, на която трябва да е числото и заменяме с това, което е там вече
    int binarySearch(const vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }    
};
