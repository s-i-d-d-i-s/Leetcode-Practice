class Solution {
public:
    
    vector<int> pathInZigZagTree(int label) {
        int left=1;
        int twoPower = 1;
        int level=0;
        while(left<=label){
            int right = left+twoPower-1;
            level++;
            if(label >= left and label <= right) break;
            left = right+1;
            twoPower *= 2;
        }
        
        vector<int> result;
        while(label>=1){
            result.push_back(label);
            level--;
            label/=2;            
            int start = powl(2,level-1);
            int end = powl(2,level)-1;
            int gap = label-start;
            label = end-gap;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};