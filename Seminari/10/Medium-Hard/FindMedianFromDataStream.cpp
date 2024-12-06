class MedianFinder {
    std::priority_queue<int> left;
    std::priority_queue<int, vector<int>, std::greater<>> right;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(right.size() == 0 || right.top() < num) {
            right.push(num);
        }
        else {
            left.push(num);
        }
        
        // move from one to the other
        if(left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if(right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        else {
            return left.size() > right.size() ? left.top() : right.top();
        }
    }
};
