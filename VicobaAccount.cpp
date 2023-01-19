#include <iostream>
#include <string>
#include <vector>
#include "VicobaAccount.h"
#include <crand>
#include <algorithm>

using namespace std;

VicobaAccount::VicobaAccount(double ab, int ld, string cn): amountBorrowed(ab), loanDuration(ld), customerName(cn){
    bool isIDUsed = true;
    string ID = "2";
    do{
        int suffix = rand() % 10000000;
        string suffixString = suffix + "";
        while(suffixString.size() < 7){
            suffixString = "0" + suffixString;
        }
        ID += suffıxStrıng;
        if(!binary_search(this->usedIDS.begin(), this->usedIDS.end(), stoi(ID))){
            //If not found set isIdUsed false
            isIdUsed = false;
            this->customerID = stoi(ID);
            this->usedIDS.push_back(this->customerID);
            sort(this->usedIDS);
        }

    }while(isIDUsed);
}
VicobaAccount::~VicobaAccount(){
    usedIDS.erase(remove(usedIDS.begin(), usedIDS.end(), this->customerID), usedIDS.end());
}
static void VicobaAccount::setAnnualInterestRate(double annualInterestRate){
    this->annualInterestRate = annualInterestRate;
}
double VicobaAccount::getCurrentDebt() const{
    double result = this->amountBorrowed;
    for(int i = 0; i < this->loanDuration; i++){
        result *= annualInterestRate;
    }
    return result;
}
double VicobaAccount::getAmountBorrowed() const{
    return this->amountBorrowed;
}
static double VicobaAccount::getAnnualInterestRate() const{
    return this->annualInterestRate;
}
int VicobaAccount::getLoanDuration() const{
    return this->loanDuration;
}
string VicobaAccount::getCustomerName(){
    return this->customerName;
}
void VicobaAccount::setAmountBorrowed(double amountBorrowed){
    this->amountBorrowed = amountBorrowed;
}
void VicobaAccount::setLoanDuration(int loanDuration){
    this->loanDuration = loanDuration;
}
void VicobaAccount::setCustomerName(string customerName){
    this->customerName = customerName;
}
string VicobaAccount::toString() const{
    string* s = &("");
    *s += "Customer name: " + this->customerName + "\n";
    *s += "Customer ID: " + this->customerID + "\n";
    *s += "Amount borrowed: " + this->amountBorrowed + "\n";
    *s += "Loan duration: " + this->loanDuration + "\n";

    return *s;
}

