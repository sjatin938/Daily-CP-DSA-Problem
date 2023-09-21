class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int> p;
    priority_queue<int> q;

void addNum(int num) {
    p.push(num);
    q.push(-p.top());
    p.pop();
    if (p.size() < q.size()) {
        p.push(-q.top());
        q.pop();
    }
}


double findMedian() {
    return p.size() > q.size() ? p.top() : (p.top() - q.top()) / 2.0;
}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */