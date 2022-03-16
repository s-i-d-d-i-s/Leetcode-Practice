// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}
// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    int l=0;
    int r=n-1;
    int leftLimit = 0;
    while(l<=r){
        int m = (l+r)/2;
        int numersMissingTillM = a[m]-a[0]+1 - (m-0+1);
        if(numersMissingTillM<k){
            leftLimit = max(leftLimit,m);
            l=m+1;
        }else{
            r=m-1;
        }
    }
    int numersMissingTillNow = a[leftLimit]-a[0]+1 - (leftLimit-0+1);
    k-=numersMissingTillNow;
    if(a[leftLimit]+k > a[n-1])return -1;
    return a[leftLimit]+k;
}