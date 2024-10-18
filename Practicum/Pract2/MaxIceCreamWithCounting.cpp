//No sorting, just histogram
class Solution {   
public:
    int findMax(vector<int>& arr, size_t arrLength) {

        int max = arr[0];
        for (int i = 0; i < arrLength; ++i) {
            if (max < arr[i]) {
                max = arr[i];
            }
        }
        return max;
    }
    

    int maxIceCream(vector<int>& costs, int coins) {
        int max = findMax(costs, costs.size());
        vector<int> countIceCream(max + 1, 0);

        for (int i = 0 ; i < costs.size(); i++) {
            countIceCream[costs[i]]++;
        }
        int buyCount = 0;

        for (int cost = 1; cost <= max; ++cost) {

            if (countIceCream[cost] > 0) {
                //kolko ot tazi cena ima, i kolko ot tazi cena max mojem da 
                //kupim (min zashtoto moje da ima po-malko otkolkoto mojem max da kupim)
              
                int count = min(countIceCream[cost], (coins / cost)); 
                buyCount += count;
                coins -= (count * cost); //namalqme parite, koito imame
            }
            if (coins < cost) {
            // If we don't have enough coins to buy even the cheapest available ice cream, break
                break;
            }
        }
        return buyCount;
    }
};
