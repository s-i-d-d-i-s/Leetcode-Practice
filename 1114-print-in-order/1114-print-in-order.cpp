class Foo {
public:
    int run[3];
    Foo() {
        memset(run,0,sizeof run);
    }
    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        while(run[0]==0){
            printFirst();
            run[0]=1;
        }
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        while(run[1]==0){
            if(run[0]==1){
                printSecond();
                run[1]=1;
            }
        }
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        while(run[2]==0){
            if(run[0]==1 and run[1]==1){
                printThird();
                run[2]=1;
            }
        }
    }
};