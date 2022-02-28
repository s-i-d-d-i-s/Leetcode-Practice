class Solution {
public:
    int getArea(vector<int>& height,int l,int r){
        int width = r-l;
        int tall = min(height[r],height[l]);
        return tall*width;
    }
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0;
        int r=n-1;
        int res = getArea(height,l,r);
        while(l<r){
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
            int current_area = getArea(height,l,r);
            res = max(res,current_area);
        }
        return res;
    }
};