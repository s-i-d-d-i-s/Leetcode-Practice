class Solution {
public:
    set<string> allPos;
    
    bool generate(string &current,int n,int k,int lim){
        if(allPos.size() == lim){
            return true;
        }
        for(int i=0;i<k;i++){
            current.push_back('0'+i);
            string temp = getLastK(current,n);
            if(allPos.find(temp) == allPos.end()){
                allPos.insert(temp);
                if(generate(current,n,k,lim))return true;
                allPos.erase(temp);
            }
            current.pop_back();
        }
        return false;
    }
    
    
    string getLastK(string &current,int k){
        int n = current.length();
        string res;
        for(int i=n-k;i<current.size();i++){
            res.push_back(current[i]);
        }
        return res;
    }
    string crackSafe(int n, int k) {
        string result(n,'0');
        allPos.insert(result);
        generate(result,n,k,powl(k,n));
        return result;
    }
};