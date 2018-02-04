#include <iostream>
#include <cassert>

enum ADC { A , B , C , D, null };

class branch
{
  public:
        branch():i(0) { }
        void set(bool e) { expr = e; }
        bool get() { if(expr) ++i; return expr; }
        unsigned int visited() { return i; }
  private:
        unsigned int i;
        bool expr;
  
};

branch b1,b2,b3,b4,b5,b6,b7,b8,b9;


void process_test(unsigned int ta, unsigned int lc) 
{
  ADC diversity;
  
    b1.set(ta > 20);
    b2.set(lc >= 4);
    b3.set(ta > 10);
    b4.set(lc == 3);
    b5.set(ta >= 5);
    b6.set(lc == 2);
    b7.set(ta > 0);
    b8.set(lc == 1);
    b9.set(true);
  
    
    if ( b1.get() || b2.get() ) diversity = A;
    else if ( b3.get() || b4.get() ) diversity = B;
    else if ( b5.get() || b6.get() ) diversity = C;
    else if ( b7.get() || b8.get() ) diversity = D;
    else { b9.get(); diversity = null; }
}


//checking each branch is reached, and only 1 time
void check()
{
    assert(b1.visited() == 1);
    assert(b2.visited() == 1);
    assert(b3.visited() == 1);
    assert(b4.visited() == 1);
    assert(b5.visited() == 1);
    assert(b6.visited() == 1);
    assert(b7.visited() == 1);
    assert(b8.visited() == 1);
    assert(b9.visited() == 1);
    
}

int main() {

    process_test(21,1);
    process_test(20,4);
    process_test(11,3);
    process_test(10,3);
    process_test(5,2);
    process_test(4,2);
    process_test(4,1);
    process_test(0,0);
     //need for full coverage , but will be not reached.
    process_test(0,1);
    
    //comment for unit-test to pass
    process_test(5,5);
  
    check();
}



