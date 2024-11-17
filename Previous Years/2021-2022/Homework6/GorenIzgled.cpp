//От Стоян
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main() {
    size_t N;
    cin >> N;
    int x, y;
    size_t leftCounter = 0, rightCounter = 0; //колко елемента има наляво и надясно, макс отклонение
    stack<size_t> leftTree; //тъй като като pop-ваме последния елемент е винаги най-левия
    queue<size_t> rightTree; //тъй като като pop-ваме последния елемент е винаги най-десния
    queue<pair<size_t, int>> nodes; // стойност,х-координата
    nodes.push(make_pair(0, 0));
    for (size_t i = 0; i < N; i++) {
        int column = nodes.front().second; //y
        nodes.pop();
        cin >> x >> y;
        if (x != -1) { //има на ляво
            nodes.push(make_pair(x, column - 1)); 
            if (column - 1 < 0 && (leftCounter < abs(column - 1))) {
                leftTree.push(x);
                leftCounter++;
            }
        }
        if (y != -1) {//има надясно
            nodes.push(make_pair(y, column + 1));
            if (column + 1 > 0 && (rightCounter < column + 1)) { //ако е за надясно и се разкланя повече от макс разклонението
                rightTree.push(y); 
                rightCounter++;
            }
        }
    }

    while (!leftTree.empty()) {
        cout << leftTree.top() << " ";
        leftTree.pop();
    }

    cout << 0 << " ";

    while (!rightTree.empty()) {
        cout << rightTree.front() << " ";
        rightTree.pop();
    }
    return 0;
}
