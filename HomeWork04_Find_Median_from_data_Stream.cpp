class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.size() == 0 || num < max_heap.top()){
            max_heap.push(num);
        }
        else{
            min_heap.push(num);
        }
        if(max_heap.size() - min_heap.size() == 2){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if(min_heap.size() - max_heap.size() == 1){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
    }
    
    double findMedian() {
        if((min_heap.size()+max_heap.size())%2 == 0) return (double(min_heap.top()) + double(max_heap.top()))/2;
        else   return double(max_heap.top());
    }
private:
    priority_queue<int,vector<int>,std::greater<int> > min_heap;
    priority_queue<int> max_heap;
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */