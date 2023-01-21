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
    const int customerID; // generate new ID each time
    static vector<int> usedIDS;
public:
    VicobaAccount(double ab,int ld, string cn);
    ~VicobaAccount();
    static void setAnnualInterestRate(double);
    double getCurrentDebt() const;

    double getAmountBorrowed() const;
    static double getAnnualInterestRate() const;
    int getLoanDuration() const;
    string getCustomerName() const;

    void setAmountBorrowed(double);
    void setLoanDuration(int);
    void setCustomerName(string);
    string toString() const;
};


#endif // VICOBA_ACCOUNT_H

