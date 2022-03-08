class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        vector<pair<int,pair<int,int>>> boxes;
        for(int i=0;i<cuboids.size();i++){
            sort(cuboids[i].begin(),cuboids[i].end());
            do{
                boxes.push_back({cuboids[i][0],{cuboids[i][1],cuboids[i][2]}});
            }while(next_permutation(cuboids[i].begin(),cuboids[i].end()));
        }
        sort(boxes.begin(),boxes.end(),[](pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){
            int baseArea_1=a.first*a.second.first;
            int baseArea_2=b.first*b.second.first;
            if(baseArea_1 == baseArea_2) return a.second.second > b.second.second;
            return baseArea_1>baseArea_2;
        });
        int dp[boxes.size()];
        dp[0]=boxes[0].second.second;
        for(int i=1;i<boxes.size();i++){
            dp[i]=boxes[i].second.second;
            for(int j=i-1;j>=0;j--){
                if(boxes[j].first>=boxes[i].first and boxes[j].second.first>=boxes[i].second.first
                  and boxes[j].second.second>=boxes[i].second.second){
                    dp[i]=max(dp[i],dp[j]+boxes[i].second.second);
                }
            }
        }
        return *max_element(dp,dp+boxes.size());
    }
};