#include "VicobaAccount.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    VicobaAccount acc1(50000, 4, "Hurdaciim");
    VicobaAccount* acc2 = new VicobaAccount(103000, 8, "Yaylacı");
    VicobaAccount acc3(35000, 2, "Zeybek");

    cout << acc1.toString() << endl;
     cout << acc2.toString() << endl;
      cout << acc3.toString() << endl;

    acc2->setCustomerName("Yaylamin Yiğidi");
    acc2->setLoanDuration(10);
    cout << acc3.getCustomerName() <<"'s debt is " << acc3.getCurrentDebt() << endl;
    cout << acc3.getCustomerName << "'s debt is " << acc3.getCurrentDebt() << endl;
    acc3.setAmountBorrowed(45000);
    VicobaAccount::setAnnualInterestRate(1.1);
    cout << acc1.getCustomerName << "'s debt is " << acc1.getCurrentDebt() << endl;

    cout << acc1.toString() << endl;
     cout << acc2.toString() << endl;
      cout << acc3.toString() << endl;



    return 0;
}
