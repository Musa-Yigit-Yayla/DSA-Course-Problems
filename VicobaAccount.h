#include <iostream>
#include <string>
#include <vector>

#ifndef VICOBA_ACCOUNT_H
#define VICOBA_ACCOUNT_H
class VicobaAccount{
private:
    double amountBorrowed;
    static double annualInterestRate = 1.2;
    int loanDuration; // in years
    string customerName;
    int customerID; // generate new ID each time
    static vector<int> usedIDS;
public:
    VicobaAccount(double ab,int ld, string cn);
    static void setAnnualInterestRate(double);
    double currentDebt();
    double getAmountBorrowed() const;
};


#endif // VICOBA_ACCOUNT_H

