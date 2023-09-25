class SmallestInfiniteSet {
public:
set<int> pq;
int cunt = 1;

int popSmallest() {
    if (pq.empty()) {
        return cunt++;
    } else {
        int res = *pq.begin();
        pq.erase(res);
        return res;
    }
}

void addBack(int num) {
    if (cunt > num)
        pq.insert(num);
}
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */