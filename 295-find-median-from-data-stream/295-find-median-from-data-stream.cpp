class MedianFinder {
public:
  priority_queue<long> small, large;
void addNum(int num) {
    small.push(num);
    large.push(-small.top());
    small.pop();
    if (small.size() < large.size()) {
        small.push(-large.top());
        large.pop();
    }
}

double findMedian() {
    return small.size() > large.size()
           ? small.top()
           : (small.top() - large.top()) / 2.0;
}
};
