class Solution {
public:
    string getHint(string secret, string guess) {

        int bull=0;
        int cow=0;

        for(int i=secret.size()-1;i>=0;i--){ //итерираме отзад напред заради erase
            int j=i;
            if(secret[i] == guess[j]){
                    bull++;
                    //използваме направо стринговете, за да премахнем биковете
                    //първоначално се грижим само за биковете, за да може после да разглеждаме само крави
                    secret.erase(secret.begin()+i); 
                    guess.erase(guess.begin()+j);
            }
        }
        
        map<char,int>ans; //frequency counter за всяко число останало в secret
        for(int i=0;i<secret.size();i++){
             ans[secret[i]]++;
        }

      //итерираме през guess
        for(int i=0;i<guess.size();i++){
            //ако открием числото и се среща още в secret, знаем, че е крава
            //следва да намалим броя на срещанията на това число, за да знаем кога са ни се изчерпали кравите за това число
            if(ans.find(guess[i])!=ans.end() && ans[guess[i]]>0){ 
                cow++;
                ans[guess[i]]--;
            }
        }

        
        
        cout<<bull<<" "<<cow;
        string s;
        string s1=to_string(bull);
        s+=s1;
        string s2=to_string(cow);
        s.push_back('A');
        s+=s2;
        s.push_back('B');
        return s;  
    }
};
