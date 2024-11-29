#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_set<int> present; 
    vector<int> permutation;    
    vector<int> free;   

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        present.insert(num);
        permutation.push_back(num);
    }

    for (int i = 1; i <= N; i++) { //искаме да разберем кои са ни свободните числа
        if (!present.count(i)) {
            free.push_back(i);
        }
    }

    sort(free.begin(), free.end()); //сортираме свободните, за да видим подредбата, с която трябва да ги добавяме

    vector<int> res; 
    int presentPtr = 0; //ще обхождаме оригиналната подредица
    int freePtr = 0;  //ще обхождаме числата, които трябва да сложим

    for (int i = 1; i <= N; i++) //минаваме през всички числа от най-малката пермутация от 1 до N
    {
        if (presentPtr < M && permutation[presentPtr] == i) //още сме в рамките на подредицата, ако е равно си го слагаме  и продължаваме към следващото
        {
            res.push_back(permutation[presentPtr]);
            presentPtr++;
        } else if (freePtr < free.size() && free[freePtr] == i) //имаме свободни и свободното трябва да е на това място, слагаме го и взимаме следващото
        {
            res.push_back(free[freePtr]);
            freePtr++;
        } else if (presentPtr < M && (freePtr >= free.size() || permutation[presentPtr] < free[freePtr])) //не сме добавили всички от подредицата, но или са свършили свободните или свободния е по-голям и няма да си е на мястото там
        {
            res.push_back(permutation[presentPtr]); 
            presentPtr++;
        } else if (freePtr < free.size()) //останали са само свободни и сме добавили всички от оригиналната подрдица
        {
            res.push_back(free[freePtr]);
            freePtr++;
        }
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}
