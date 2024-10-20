//по-умното решение, подобно на first missing positive // O(n)

//chisloto, koeto stoi na index-a na nums[i] otgovarq za chisloto num = nums[i]
//nqma go - nishto
//ima go 1 put - negativna stoinost na chisloto, koeto otgovarq za nego
//ima go 2 puti - dobavqme kato otgovarqshtoto e s negativna stojnost
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> output;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            int num = abs(nums[i]);

            if(nums[num-1] < 0) //izpolzvame [1...n] kato count vmesto da zadelqme pamet za nov masiv, zatova vzimame i abs stojnost
            {
                output.push_back(num);
            }
            nums[num-1] *= -1; //sreshtnali sme go - otbelqzwame (ako e negative znachi sme go vidqli vednuj i kato go sreshtnem pak shte bude vtori put)
        }
        return output;
    }
};
