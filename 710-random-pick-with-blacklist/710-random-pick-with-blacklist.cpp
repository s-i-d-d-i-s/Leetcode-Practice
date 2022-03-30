class Solution {
public:
    int max;
    map<int,int> index;
    Solution(int n, vector<int>& blacklist) {
        max = n;
        unordered_map<int,bool> isBlacklist;
        
        sort(blacklist.begin(),blacklist.end());
        
        for(int x:blacklist)
            isBlacklist[x]=true;
        
        for(int i=0;i<blacklist.size();i++){
            int idx = blacklist[i]; 
            if(idx<max){
                if(index.find(idx) == index.end()) index[idx] = blacklist[i];
                if(isBlacklist[index[idx]] == false) continue;                                     
                index[idx] = max-1;
                max--;
                i--;
            }
        }
        cout << max << endl;
    }
    
    int pick() {        
        int idx = rand()%max;
        if(index.find(idx) == index.end()) index[idx] = idx;
        int result = index[idx];
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */