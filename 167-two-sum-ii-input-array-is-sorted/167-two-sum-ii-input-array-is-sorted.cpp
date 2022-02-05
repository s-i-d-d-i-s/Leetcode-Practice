class Solution {
public:
    int findElement(vector<int> &a,int l,int r,int x){
        while(l<=r){
            int m = (l+r)/2;
            if(a[m] == x){
                return m;
            }else if(a[m] < x){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        for(int i=0;i<numbers.size();i++){
            int neededNumber = target - numbers[i];            
            int numberGot = findElement(numbers,i+1,numbers.size()-1,neededNumber);            
            if(numberGot == -1)continue;                        
            result.push_back(i+1);
            result.push_back(numberGot+1);
            break;
        }
        return result;
    }
};