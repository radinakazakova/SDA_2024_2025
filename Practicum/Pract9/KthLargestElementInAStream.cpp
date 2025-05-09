class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; //minHeap, за да останат к на брой най-голeми числа
    int k;
    KthLargest(int k, vector<int>& nums) : k(k) {
        
        for (int num : nums) {
            pq.push(num);
        }

        while(pq.size() > k) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
