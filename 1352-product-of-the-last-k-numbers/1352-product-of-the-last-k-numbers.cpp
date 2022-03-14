class ProductOfNumbers {
public:
    vector<int> prefix;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num !=0 ){
            if(prefix.size()>0)
                prefix.push_back(prefix.back()*num);
            else
                prefix.push_back(num);
        }else{
            prefix.clear();
        }
    }
    
    int getProduct(int k) {
        if(k>prefix.size())return 0;
        int l=prefix.size()-k;
        if(l-1>=0)
            return prefix.back()/prefix[l-1];
        return prefix.back();
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */