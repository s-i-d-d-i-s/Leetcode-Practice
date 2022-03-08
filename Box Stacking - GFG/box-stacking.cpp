// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
        vector<pair<int,pair<int,int>>> boxes;
        
        // l        w       h
        
        for(int i=0;i<n;i++){
            boxes.push_back({height[i],{width[i],length[i]}});
            boxes.push_back({height[i],{length[i],width[i]}});
            
            boxes.push_back({width[i],{height[i],length[i]}});
            boxes.push_back({width[i],{length[i],height[i]}});
            
            boxes.push_back({length[i],{height[i],width[i]}});
            boxes.push_back({length[i],{width[i],height[i]}});
        }
        sort(boxes.begin(),boxes.end(),[](pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){
           int baseArea_1=a.first*a.second.first;
           int baseArea_2=b.first*b.second.first;
           return baseArea_1>baseArea_2;
        });
        int dp[boxes.size()];
        dp[0]=boxes[0].second.second;
        for(int i=1;i<boxes.size();i++){
            dp[i]=boxes[i].second.second;
            for(int j=i-1;j>=0;j--){
                if(boxes[j].first>boxes[i].first and boxes[j].second.first>boxes[i].second.first){
                    dp[i]=max(dp[i],dp[j]+boxes[i].second.second);
                }
            }
        }
        return *max_element(dp,dp+boxes.size());
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	  // } Driver Code Ends