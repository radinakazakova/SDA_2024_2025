//O(n*logN) time
//O(n) pamet
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int minCnt = n/3;

        sort(nums.begin(), nums.end());
        vector<int> res;
        int prev = 0;
        for(int i = 0; i < n; i++)
        {
          //vajno e, che purvata proverka e dali sme na posledniq element, zashtoto sledvashtata proverka nqma da se izpulni (tq e nevalidna), i posle shte smetnem pravilno dali da go vkluchim
            if(i+1 == n || nums[i+1] != nums[prev]) //iterirame, dokato ne namerim razlichen element (izbqgvame O(n^2))
            {
                if(i+1 - prev > minCnt) //i+1 - prev = kolko elementa ima v intervala ot predishnoto purvo chislo do purvoto novo
                {
                    res.push_back(nums[prev]);
                }
                prev = i + 1; //update-vame purvoto novo chislo
            }
        }
        return res;
    }
};
