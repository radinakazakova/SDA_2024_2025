class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        //ще пресмятаме колко ребра влизат във всеки node
        //ако не влиза нито един, знаем, че той може да е победител
        //ако има няколко, в които не влизат ребра: -1
        vector<int> in_degree(n, 0);

        for(auto& edge: edges)
        {
            in_degree[edge[1]]++;
        }

        int count = 0;
        int possibleChamp = 0;
        //обхождаме всички възли, тъй като знаем, че са от 0 до n-1
        for(int i = 0; i < n; i++)
        {
            if(in_degree[i] == 0){
                count++;
                possibleChamp = i; //трябва ни само ако count e 1, иначе пази последния намерен champion
            }
        }

        return count == 1 ? possibleChamp : -1;
    }
};
