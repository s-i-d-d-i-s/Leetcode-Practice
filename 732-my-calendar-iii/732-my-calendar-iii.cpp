class MyCalendarThree {
public:
    map<int,int> line;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        line[start]++;
        line[end]--;
        int cur=0;
        int result=0;
        for(auto x:line){
            cur+=x.second;
            result = max(result,cur);
        }
        return result;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */