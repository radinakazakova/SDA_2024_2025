//моето супер бавно първо решение
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, unordered_set<int>> myNumber;
        unordered_map<char, int> freq;
        int size = secret.size();
        for(int i = 0; i<size; i++)
        {
            myNumber[secret[i]].insert(i);
            freq[secret[i]]++;
        }

        int guessSize = guess.size();
        int bullsCount = 0;
        int cowsCount = 0;
        unordered_map<char, int> potentialCows;

        for(int i = 0; i < guessSize; i++)
        {
            if(myNumber.count(guess[i]))
            {
                if(myNumber[guess[i]].count(i) && freq[guess[i]])
                {
                    bullsCount++;
                    myNumber[guess[i]].erase(i);
                    freq[guess[i]]--;
                }
                else if(myNumber.count(guess[i]) && freq[guess[i]])
                {
                    //potencialen cow - namiram posle che e bull trqbva da namalq cowCount
                    cowsCount++;
                    potentialCows[guess[i]]++; 
                }
            }

            //ako potencialnite kravi za edno chislo sa poveche ot tezi koito sa ostanali v secret - potencialnte sa ravni na ostanalite v secret
            if(potentialCows[guess[i]] > freq[guess[i]])
            {
                cowsCount -= potentialCows[guess[i]] - freq[guess[i]];
                potentialCows[guess[i]]--;
            }
        }

       string res;
       res += std::to_string(bullsCount);
       res += "A";
       res += std::to_string(cowsCount);
       res += "B";

       return res;
    }
};
