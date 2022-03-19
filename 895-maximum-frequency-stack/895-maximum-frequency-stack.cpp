class FreqStack {
public:
    unordered_map<int,stack<int>> freqStk;
    unordered_map<int,int> freq;
    int maxFreq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq,freq[val]);
        freqStk[freq[val]].push(val);
    }
    
    int pop() {
        int result = freqStk[maxFreq].top();
        freq[result]--;
        freqStk[maxFreq].pop();
        if(freqStk[maxFreq].size()==0){
            maxFreq--;
        }
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */