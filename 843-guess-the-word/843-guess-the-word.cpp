/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int n = wordlist.size();
        srand(time(NULL));
        int foo = 9;
        while(foo--){
            random_shuffle(wordlist.begin(),wordlist.end());
            string guessWord = wordlist[0];
            int count = master.guess(guessWord);
            vector<string> filteredWords;
            for(auto x:wordlist){
                if(myGuess(x,guessWord) == count){
                    filteredWords.push_back(x);
                }
            }
            wordlist=filteredWords;
        }
         master.guess(wordlist[0]);
        return ;
    }
    int myGuess(string &a,string &b){
        int result=0;
        for(int i=0;i<a.length();i++){
            result += (a[i] == b[i]);
        }
        return result;
    }
};