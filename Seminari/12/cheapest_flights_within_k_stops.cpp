struct Edge
{
    int from, to, price;
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);

        prices[src] = 0;

        for(int i = 0; i <= k; i++)
        {
            vector<int> nextRow(prices);
            //в price ще запазим каквото сме намерили до сега (предния level)
            //в nextrow ще ъпдейтваме новите стойности с помощта на prices
            //(например всички в началото са int_max) ако минем първо през реброто 0->1 и после 1->2 ще имаме записана стойност 100 за 1, а не INT_MAX,
            //което ние искаме да знаем заради k (иначе губим колко пъти сме се прикачили)
            for(auto& edge: flights) 
            {
                if(prices[edge[0]] != INT_MAX) 
                {
                    nextRow[edge[1]] = min(nextRow[edge[1]], prices[edge[0]] + edge[2]);
                }
            }
            
            prices = std::move(nextRow);
        }

        if(prices[dst] == INT_MAX)
            return -1;
        return prices[dst];
    }
};
