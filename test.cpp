#include <iostream>
#include <cassert>

enum accountDiversityGrade { A , B , C , D, null };

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


void process_test(unsigned int totalAccounts, unsigned int loanTypeCount) 
{
  accountDiversityGrade diversity;
  
    b1.set(totalAccounts > 20);
    b2.set(loanTypeCount >= 4);
    b3.set(totalAccounts> 10);
    b4.set(loanTypeCount == 3);
    b5.set(totalAccounts>= 5);
    b6.set(loanTypeCount == 2);
    b7.set(totalAccounts > 0);
    b8.set(loanTypeCount == 1);
    b9.set(true);
  
    
    if ( b1.get() || b2.get() ) diversity = A;
    else if ( b3.get() || b4.get() ) diversity = B;
    else if ( b5.get() || b6.get() ) diversity = C;
    else if ( b7.get() || b8.get() ) diversity = D;
    else { b9.get(); diversity = null; }
}


void check()
{
       
    
    assert(b1.visited() > 0);
    assert(b2.visited() > 0);
    assert(b3.visited() > 0);
    assert(b4.visited() > 0);
    assert(b5.visited() > 0);
    assert(b6.visited() > 0);
    assert(b7.visited() > 0);
    assert(b8.visited() > 0);
    assert(b9.visited() > 0);
    
}

int main() {

    process_test(21,1);
    process_test(20,4);
    process_test(11,3);
    process_test(10,3);
    process_test(5,2);
    process_test(4,2);
    process_test(4,1);
     //need for full coverage.
    process_test(0,1);
    process_test(0,0);
      
    check();
}



