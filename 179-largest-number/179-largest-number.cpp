class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> resultArray;
        for(auto x:nums){
            resultArray.push_back(to_string(x));
        }
        
        sort(resultArray.begin(),resultArray.end(),[](string &a,string &b){
            return a+b > b+a;
        });
        
        string result = "";
        
        for(auto x:resultArray)
            result += x;
        
        reverse(result.begin(),result.end());
        
        while(result.length() and result.back()=='0') result.pop_back();
        
        reverse(result.begin(),result.end());
        
        return result.length()>0?result:"0";
    }
};