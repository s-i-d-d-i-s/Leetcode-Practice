class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int least = getLeast(arr,target);
        int most = getMost(arr,target);
       // cout << least << " " << most << endl;
        int d1 = abs(target-getSum(arr,least));
        int d2 = abs(target-getSum(arr,most));
        if(d1<=d2){
            return least;
        }
        return most;
    }
    
    int getLeast(vector<int>& arr, int target){
        int l=0;
        int r=*max_element(arr.begin(),arr.end());
        int result = 0;
        while(l<=r){
            int m = (l+r)/2;
            if(getSum(arr,m)<=target){
                result = max(result,m);
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return result;
    }
    
    int getMost(vector<int>& arr, int target){
        int l=0;
        int r=*max_element(arr.begin(),arr.end());
        int result = INT_MAX;
        while(l<=r){
            int m = (l+r)/2;
            if(getSum(arr,m)<target){
                l=m+1;
            }else{
                result = min(result,m);
                r=m-1;
            }
        }
        return result;
    }
    
    int getSum(vector<int>& arr, int val){
        int result=0;
        for(int x:arr){
            result += min(x,val);
        }
        return result;
    }
};