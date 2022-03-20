class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int maximum = *max_element(arr.begin(),arr.end());
        int totalSum = accumulate(arr.begin(),arr.end(),0);
        int result = maximum;
        int diff = INT_MAX;
        int right=0;
        for(int i=maximum;i>=0;i--){
            while(arr.size()>0 and arr.back()>=i){
                right++;
                totalSum -= arr.back();
                arr.pop_back();
            }
            int current = right*i + totalSum;
            int current_difference = abs(current-target);
            if(current_difference<diff){
                diff=current_difference;
                result = i;
            }else if(diff == current_difference)
                result = i;
        }
        return result;
    }
};