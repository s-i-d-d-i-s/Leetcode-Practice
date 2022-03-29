/*

        1 2 3 4 |  5 6 7
        
        1 2 3 | 5 6 7
*/

class MedianFinder {
public:
    multiset<int> left,right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()==0){
            left.insert(num);
            return;
        }
        
        if(right.size()==0){
            int lastOnLeft = getLast(left);            
            if(num<lastOnLeft){
                left.erase(left.find(lastOnLeft));
                left.insert(num);
                right.insert(lastOnLeft);
            }else{
                right.insert(num);
            }
            return;
        }
        
        int leftMax = getLast(left);
        int rightMin = getFirst(right);
        if(num<=leftMax){
            left.insert(num);
        }else{
            right.insert(num);
        }
        balancing();
    }
    
    double findMedian() {
        int n = left.size();
        int m = right.size();
        if(m==0) return getFirst(left);
        
        if((n+m) % 2 == 0){
            return (double)(getLast(left)+getFirst(right))/2.0;
        }else{
            if(n>m)
                return getLast(left);
            
            return getFirst(right);
        }
        return 0.0;
    }
    
    int getFirst(multiset<int> &a){
        return a.size()>0?*a.begin():INT_MIN;
    }
    int getLast(multiset<int> &a){
        return a.size()>0?*(--a.end()):INT_MIN;
    }
    
    void balancing(){
        if(left.size()>right.size()+1){
            int lastOnLeft = getLast(left);
            left.erase(left.find(lastOnLeft));
            right.insert(lastOnLeft);
        }else if(right.size()>left.size()+1){
            int firstOnRight = getFirst(right);
            right.erase(right.find(firstOnRight));
            left.insert(firstOnRight);
        }
        return;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */