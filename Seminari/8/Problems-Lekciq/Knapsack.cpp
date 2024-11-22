// A dynamic programming based
// solution for 0-1 Knapsack problem

//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int cap, int weight[], int val[], int n)
{
    vector<vector<int> > K(n + 1 /* s nulata*/, vector<int>(cap + 1) /* s nulata*/); //матрица в която пазим за всяко capacity на всеки килограм колко ще е макса на values до момента

    // Build table K[][] in bottom up manner
    for (int i = 0; i <= n; i++) { //за всеки weight
        for (int w = 0; w <= cap; w++) { //за всяко capacity
            if (i == 0 || w == 0)
                K[i][w] = 0; // база
            else if (weight[i - 1] <= w) //сегашното дали е в капаситито (i-1 отговаря на сегашното в weight и values)
                K[i][w] = max(val[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]); //предходното намерено за капаситито или новото value + предходното намерено за cap - curr weight
            else
                K[i][w] = K[i - 1][w]; //предходното намерено
        }
    }
    return K[n][cap];
}

// Driver Code
int main()
{
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int cap = 50;
    int n = sizeof(profit) / sizeof(profit[0]);

    cout << knapSack(cap, weight, profit, n);

    return 0;
}

// This code is contributed by Debojyoti Mandal
