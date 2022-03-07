class MyCalendarTwo {
public:
    map<int,int> line;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        line[startTime]++;
        line[endTime]--;
        int booked=0;
        for(auto x:line){
            booked+=x.second;
            if(booked >= 3){
                line[startTime]--;
                line[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */