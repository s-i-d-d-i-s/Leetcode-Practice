class MyCalendarTwo {
public:
    vector<int> start,ends;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        vector<int> tempStart = start;
        vector<int> tempEnd = ends;
        
        tempStart.push_back(startTime);
        tempEnd.push_back(endTime);
        
        sort(tempStart.begin(),tempStart.end());
        sort(tempEnd.begin(),tempEnd.end());

        int result=0;
        int current=0;
        int i=0;
        int j=0;
        while(i<tempStart.size() and j<tempEnd.size()){
            if(tempStart[i] < tempEnd[j]){
                i++;
                current++;
            }else if( tempEnd[j]  < tempStart[i]){
                j++;
                current--;
            }else{
                i++;
                j++;
            }
            result = max(result,current);
        }
        if(result < 3){
            start.push_back(startTime);
            ends.push_back(endTime);
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */