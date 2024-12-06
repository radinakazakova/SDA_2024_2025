int cookies(int k, vector<int> A) {
    if(A.empty() || (A.size() == 1 && A[0] < k))
        return -1;
        
    std::priority_queue<long long, vector<long long>, std::greater<>> pq(A.begin(), A.end());
    int count = 0;
        
    while(!pq.empty() && pq.top() < k && pq.size() > 1)
    {
        long long firstSmallest = pq.top();
        pq.pop();
        long long secondSmallest = pq.top();
        pq.pop();
        
        pq.push(firstSmallest + 2*secondSmallest);
        count++;
    }
    
    if(pq.top() < k && pq.size() == 1)
        return -1;
    return count;
}
