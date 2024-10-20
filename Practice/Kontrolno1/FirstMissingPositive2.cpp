//O(n) s dopulnitelno pamet
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n+1,-1); //n+1 zaradi nulata

        for(int i = 0; i<n; i++)
        {
            if(nums[i] > 0 && nums[i]<=n) //negativnite i po-golemite ot 'n' gi ignorirame
                count[nums[i]]++; //counting kakvoto vidim, max 'n' moje da ni e missing
        }

        for(int i = 1 ; i<count.size(); i++)
        {
            if(count[i] == -1){ //ako go nqma - to e
                return i;
            }
        }
        return n+1; //ako ne sme go namerili znachi e sledvashtoto chislo
    }
};
