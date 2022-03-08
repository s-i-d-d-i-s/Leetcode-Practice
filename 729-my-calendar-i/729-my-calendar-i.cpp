class MyCalendar {
public:
    map<int,int> line;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        line[start]++;
        line[end]--;
        int cur=0;
        for(auto x:line){
            cur+=x.second;
            if(cur>=2){
                line[start]--;
                line[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */