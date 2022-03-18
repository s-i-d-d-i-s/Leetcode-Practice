class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
            If gaps get finished, no worries
            https://leetcode.com/problems/task-scheduler/discuss/370755/C%2B%2B-solution-95-time-and-space-with-good-explanation
        */
        unordered_map<char,int> freq;
        
        int maximum_freq = 0;
        for(auto x:tasks){
            freq[x]++;
            maximum_freq = max(maximum_freq,freq[x]);
        }
        
        int maximum_freq_num_count = 0;
        
        for(auto x:freq){
            if(x.second == maximum_freq)
                maximum_freq_num_count++;
        }
        
        int chunkSize = n-(maximum_freq_num_count-1);
        int gaps = chunkSize*(maximum_freq - 1);
        
        
        for(auto x:freq){
            if(x.second != maximum_freq){
                gaps -= x.second;
            }
        }
        gaps = max(0,gaps);
        return gaps + tasks.size();
    }
};