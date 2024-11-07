class RecentCounter {
public:
    queue<int> container;
    
    int ping(int t) { //подават ни t в нарастващ ред, тоест по-малките са отпред : queue
        while(!container.empty() && container.front() < t - 3000) { //ако са по-малки от долната граница ги махаме
            container.pop();
        }
        container.push(t);
        
        return container.size();
    }
};
