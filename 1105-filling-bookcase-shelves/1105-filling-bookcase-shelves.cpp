class Solution {
public:
    int dp[1001][1001+5];
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof dp);
        return getMinHeightShelves(0,books,shelfWidth+1,0,shelfWidth);
    }
    int getMinHeightShelves(int idx,vector<vector<int>>& books, int shelfFilled,int currentHeight,int shelfWidth) {
        if(idx>=books.size())
            return currentHeight;
        if(dp[idx][shelfFilled] != -1){
            return dp[idx][shelfFilled];
        }
        if(shelfFilled+books[idx][0] <= shelfWidth){
            int addBookToShelf = getMinHeightShelves(idx+1,books,shelfFilled+books[idx][0],max(currentHeight,books[idx][1]),shelfWidth);
            int createNewShelf = currentHeight+getMinHeightShelves(idx+1,books,books[idx][0],books[idx][1],shelfWidth);
            return dp[idx][shelfFilled] = min(addBookToShelf,createNewShelf);
        }
        int createNewShelf = currentHeight+getMinHeightShelves(idx+1,books,books[idx][0],books[idx][1],shelfWidth);
        return dp[idx][shelfFilled] = createNewShelf;
    }
};