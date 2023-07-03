#include <iostream>
#include <cmath>

class PowerOfNumbers{
    public:
    //You need to complete this fucntion
    const long long q = (pow(10, 9) + 7);

    long long power(int N,int R)
    {
       //Your code here

      // if(R == 0){
        //   return 1;
       //}
       if(R == 1){
           return N;
       }

       long long half = power(N, R / 2);
       long long result;
       if(R % 2 == 0){
            result = power(N, R / 2);
            result *= result;
       }
       else{
            //odd
            result = power(N, R / 2) * power(N, R / 2 + 1);
       }
       //long long result = power(N, R - 1) * N;

        result = result % q;
        return result;
    }
};
