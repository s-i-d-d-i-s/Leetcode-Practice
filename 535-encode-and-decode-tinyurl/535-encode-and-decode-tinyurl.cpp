class Solution {
public:
    map<string,string> hashMap;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while(true){
            string currentHash = getHash();
            if(hashMap.count(currentHash))
                continue;
            hashMap[currentHash] = longUrl;
            return currentHash;
        }
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return hashMap[shortUrl];
    }
    string getHash(){
        string result="";
        for(int i=0;i<6;i++){
            int type = rand()%3;
            if(type == 0)
                result += (rand()%26 + 'a');
            else if(type == 1)
                result += (rand()%26 + 'A');
            else
                result += (rand()%10 + '0');
        }
        return result;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));