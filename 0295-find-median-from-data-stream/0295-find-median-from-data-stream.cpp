class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    double median = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || num <= maxheap.top()){
            maxheap.push(num);
        }
        else{
            minheap.push(num);
        }

        if(maxheap.size() > minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }

        if(minheap.size() > maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        double med = 0;
        if(maxheap.size() == minheap.size()){
            med += maxheap.top();
            med += minheap.top();
            med/=2;
        }
        else if(maxheap.size() > minheap.size()){
            med = maxheap.top();
        }
        else{
            med = minheap.top();
        }
        median = med;
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */