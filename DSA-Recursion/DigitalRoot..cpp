#include "DigitalRoot.h"

/*int DigitalRoot::digitalRoot(int n){
        //Your code here
   return DigitalRoot::helper(n, 0);
}
    //sum denotes what has been summed of digits so far
int DigitalRoot::helper(int n, int sum){
    if(n == 0){
        if(sum < 10){
            return sum;
        }
        else{
            return helper(sum, 0);
        }
    }
    sum += n % 10;
    return helper(n / 10, sum);

}*/
int DigitalRoot::calculateSubsetSum(int a[]){
        subsetSum(a, 0, 0);
        return this->noOfSums;
    }
void DigitalRoot::subsetSum(int a[], int sum, int index){
    if(index == (sizeof(a) / sizeof(a[0])) && sum == DigitalRoot::desiredSum){
        DigitalRoot::noOfSums++;
        return;
    }
    DigitalRoot::subsetSum(a, sum, index + 1);
    DigitalRoot::subsetSum(a, sum + a[index], index + 1);
}
