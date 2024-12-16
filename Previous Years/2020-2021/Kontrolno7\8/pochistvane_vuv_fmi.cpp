#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int time;
    int type;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<Event> events;
    vector<int> queries(Q);

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        events.push_back({start, +1});
        events.push_back({end + 1, -1});
    }

    for (int i = 0; i < Q; i++) {
        cin >> queries[i];
    }

    sort(events.begin(), events.end(), [](const Event &a, const Event &b) {
        return a.time < b.time || (a.time == b.time && a.type < b.type); //тъй като имаме end +1 ,използваме < за type първо ще премахнем end преди да обработим start евентуално
    });

    vector<pair<int, int>> sortedQueries;
    for (int i = 0; i < Q; i++) {
        sortedQueries.push_back({queries[i], i});
    }
    sort(sortedQueries.begin(), sortedQueries.end());

    vector<int> answers(Q);
    int currentCount = 0;
    size_t eventIndex = 0;

    for (const auto &query : sortedQueries) {
        int queryTime = query.first;
        int queryIndex = query.second;

      //изчисляваме броят на хората преди времето, което ни е подадено, за всяко query
        while (eventIndex < events.size() && events[eventIndex].time <= queryTime) {
            currentCount += events[eventIndex].type;
            eventIndex++;
        }

        answers[queryIndex] = currentCount;
    }

    for (int i = 0; i < Q; i++) {
        cout << answers[i] << " ";
    }

    return 0;
}
