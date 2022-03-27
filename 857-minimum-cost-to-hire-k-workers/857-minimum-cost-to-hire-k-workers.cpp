class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        /*
            Condition for wage
            1.  -> offer[x] = (quality[x] * expWage[cap])/quality[cap]
                -> offer[x] = quality[x] * ratio[cap]       where ratio[x] = expWage[x]/quality[x]
            
            Condition for offer to be accepted
            2.    offer[x] >= expWage[x]
                -> quality[x] * ratio[cap] >= expWage[x]
                -> ratio[cap] >= expWage[x] / quality[x]
                -> ratio[cap] >= ratio[x]
            
        */
        int n=quality.size();
        
        vector<pair<double,int>> workers(n);
        for(int i=0;i<n;i++){
            workers[i] = {wage[i]/(double)quality[i],i};
        }
        
        sort(workers.begin(),workers.end());
        
        multiset<int> window;
        
        double sum = 0;
        double result=INT_MAX;
        
        for(int i=0;i<k-1;i++){
            int idx = workers[i].second;
            sum += quality[idx];
            window.insert(quality[idx]);
        }
        
        for(int i=k-1;i<n;i++){
            int idx = workers[i].second;
            
            double ratio = wage[idx]/(double)quality[idx];
            result = min(result,ratio*sum+wage[idx]);
            
            sum += quality[idx];
            window.insert(quality[idx]);
            
            auto minimum = *(--window.end());
            window.erase(--window.end());            
            sum -= minimum;
        }
        
        return result;
    }
};
