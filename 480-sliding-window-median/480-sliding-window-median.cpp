
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
    
    void removeNum(int num) {
        int n = ms.size();
        int curNum = *mid;
        
        if(n & 1){
            if(num < curNum){
                ms.erase(ms.find(num));
            }else if(num > curNum){
                ms.erase(ms.find(num));
                mid--;
            }else{
                auto toRem = ms.find(num);
                auto it = mid;
                if(it == toRem){
                    it--;
                    ms.erase(toRem);
                    mid=it;
                }else{
                    ms.erase(toRem);
                }
            }
        }else{
            if(num < curNum){
                ms.erase(ms.find(num));
                mid++;
            }else if(num>curNum){
                ms.erase(ms.find(num));
            }else{
                auto toRem = ms.find(num);
                auto it = mid;
                if(it == toRem){
                    it++;
                    ms.erase(toRem);
                    mid=it;
                }else{
                    ms.erase(toRem);
                    mid++;
                }
            }
        }
    }    
    // 1 2 3 3  3 3 4 5
    // 1 2 2 3  3 3 4 5
    double findMedian() {
        int n = ms.size();
        if(n&1){
            return *mid;
        }else{
            auto nextIt = mid;
            nextIt++;
            double result = (long long)(*mid) + (long long)(*nextIt);
            result/=2.0;
            return result;
        }
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        MedianFinder mf;
        for(int i=0;i<k;i++){
            mf.addNum(nums[i]);
        }
        vector<double> result;
        result.push_back(mf.findMedian());
        for(int i=k;i<nums.size();i++){
            mf.addNum(nums[i]);
            mf.removeNum(nums[i-k]);            
            result.push_back(mf.findMedian());
        }
        return result;
    }
};

