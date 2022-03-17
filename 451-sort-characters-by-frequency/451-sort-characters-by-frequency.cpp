class Solution {
public:
    string frequencySort(string s) {
        int bufferSize='z'-'0'+1;
        int freq[bufferSize];
        cout << bufferSize << endl;
        memset(freq,0,sizeof freq);
        for(char x:s){            
            freq[x-'0']++;
        }
        string result="";
        for(int i=0;i<bufferSize;i++){
            int maxi = 0;
            char last='*';
            for(int j=0;j<bufferSize;j++){
                if(freq[j]>maxi){
                    maxi=freq[j];
                    last=j+'0';
                }
            }
            while(maxi>0){
                result.push_back(last);
                maxi--;
                freq[last-'0']=0;
            }            
        }
        return result;
    }
};