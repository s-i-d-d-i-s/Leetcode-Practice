class StockSpanner {
public:
    stack<pair<int,int>> stk;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int result=0;
        while(stk.size()>0 and stk.top().first<=price){
            result+=stk.top().second;
            stk.pop();            
        }        
        result++;
        stk.push({price,result});
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */