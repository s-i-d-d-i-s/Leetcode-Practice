class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(),deck.end());
        deque<int> dq;
        vector<int> result;
        int pt=n-1;
        while(pt>=0){
            rotate(dq);
            dq.push_front(deck[pt]);
            pt--;
        }
        while(dq.size()>0){
            result.push_back(dq.front());
            dq.pop_front();
        }
        return result;
    }
    void rotate(deque<int> &dq){
        if(dq.size()==0)return;
        int last = dq.back();
        dq.pop_back();
        dq.push_front(last);
    }
};