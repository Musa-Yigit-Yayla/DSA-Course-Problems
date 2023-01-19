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


