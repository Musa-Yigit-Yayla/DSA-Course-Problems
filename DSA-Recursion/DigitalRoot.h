#ifndef DIGITALROOT_H
#define DIGITALROOT_H

class DigitalRoot{
private:
    int desiredSum = 8;
    int noOfSums = 0;
public:
    int helper();
    int digitalRoot(int n);
    int calculateSubsetSum(int a[]);
    void subsetSum(int a[], int sum, int index);

};
#endif // DIGITALROOT_H
