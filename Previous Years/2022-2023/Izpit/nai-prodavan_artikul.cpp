#include <bits/stdc++.h>
using namespace std;

struct Pair {
    size_t id;
    size_t time;
};

unordered_map<size_t, int> moneyMap; // (time -> id with the highest count)
unordered_map<int, size_t> counter; // (id -> count)

int main() {
    size_t time, T, N, id;
    cin >> N;

    queue <Pair> p;
    set <size_t> times;
    size_t maxTime = 0;
    for (size_t i = 0; i < N; ++i) {
        cin >> id >> time;
        p.push({id, time});
        times.insert(time);
        maxTime = max(time, maxTime);
    }

    long long maxPair = 0;
    long long maxId = -1;
    while (!p.empty()) {
        size_t currentId = p.front().id;
        counter[currentId]++;
        if (counter[currentId] >= maxPair) { //след най-купувания артикул
            maxPair = counter[currentId];
            maxId = currentId;
        }
        moneyMap[p.front().time] = maxId; //добавяме за текущото време кой артикул е най-купуван
        p.pop();
    }

    cin >> T;
    for (size_t i = 0; i < T; ++i) {
        cin >> time;
        if (time >= maxTime) {
            cout << moneyMap[maxTime] << '\n';
            continue;
        }
        auto tempTime = times.lower_bound(time);
        if (time < *tempTime) {
            if (tempTime == times.begin()) { //преди първото ни време
                cout << -1 << '\n';
                continue;
            }
            time = *(--tempTime);
        } else {
            time = *tempTime;
        }

        cout << moneyMap[time] << '\n';
    }
    return 0;
}
