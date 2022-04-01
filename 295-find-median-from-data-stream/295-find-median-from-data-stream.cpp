class MedianFinder {
public:
    multiset<int> ms;
    multiset<int>::iterator mid;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(ms.size()==0){
            ms.insert(num);
            mid = ms.begin();
        }else{
            int n = ms.size();
            ms.insert(num);
            if(n & 1){
                if(num >= (*mid)){
                    // Do nothing
                }else{
                    mid--;
                }
            }else{
                if(num >= (*mid)){
                    mid++;
                }else{
                    // do nothing
                }
            }
        }
    }
    
    double findMedian() {
        int n = ms.size();
        if(n&1){
            return *mid;
        }else{
            auto nextIt = mid;
            nextIt++;
            double result = (*mid) + (*nextIt);
            result/=2.0;
            return result;
        }
    }
};




/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */