template <typename T>
vector<string> split(string &a){
	function<bool (T, T)> cond = [&](T a, T b) {
		// Write Your Split Condition
        if(a == '/' or b=='/') return true;
		return false;
	};
	vector<string> res;
	string cur;
	cur.push_back(a[0]);
	for(int i=1;i<a.size();i++){
		if(cond(a[i-1],a[i])){
            if(cur.length()>0 and cur[0]!='/')
			res.push_back(cur);
			cur.clear();
		}
		cur.push_back(a[i]);
	}
	if(cur.length()>0 and cur[0]!='/')
        res.push_back(cur);
	return res;
}

class Solution {
public:
    string simplifyPath(string path) {
        auto tokens = split<char>(path);
        vector<string> stk;
        for(auto x:tokens){
            if(x==".")continue;
            if(x==".."){
                if(stk.size()>0){
                    stk.pop_back();
                }
            }else{
                stk.push_back(x);
            }
        }
        string result="";
        for(auto x:stk){
            result+="/"+x;
        }
        if(result.length()==0)result="/";
        return result;
    }
};