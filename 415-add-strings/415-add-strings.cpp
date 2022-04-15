class Solution {
public:
    string addStrings(string a, string b) {
        int carry=0;
        string result="";
        int i=a.length()-1;
        int j=b.length()-1;
        while(i>=0 and j>=0){
            int d1=a[i]-'0';
            int d2=b[j]-'0';
            int sum = d1+d2+carry;
            result.push_back(sum%10+'0');
            carry = sum/10;
            i--;
            j--;
        }
        while(i>=0){
            int d1=a[i]-'0';
            int d2=0;
            int sum = d1+d2+carry;
            result.push_back(sum%10+'0');
            carry = sum/10;
            i--;
        }
        while(j>=0){
            int d1=0;
            int d2=b[j]-'0';
            int sum = d1+d2+carry;
            result.push_back(sum%10+'0');
            carry = sum/10;
            j--;
        }
        if(carry>0){
            result.push_back(carry%10 + '0');
        }
        reverse(result.begin(),result.end());
        return result;
    }
};