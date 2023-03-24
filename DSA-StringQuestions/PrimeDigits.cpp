#include <string>
#include <iostream>

using namespace std;
class PrimeDigits{
public:
    //Function to find nth number made of only prime digits.
    int primeDigits(int n){
        //code here
        int result = 2;
        int counter = 1;

        while(counter <= n){
            //string s = "" + result;
            if(isPrimeDigited(result)){
                counter++;
            }
            result++;
        }
        return result;
    }
    bool isPrimeDigited(const string& s){
        for(int i = 0; i < s.size(); i++){
            int ch;
            string str;
            if(i != s.size() - 1){
                str = s.substr(i, i + 1);
                cout << str << endl;
                ch = stoi(str);
            }
            else{
                str = s.substr(i);
                ch = stoi(str);
            }
            if(!isPrimeDigit(ch)){
                return false;
            }
        }
        return true;
    }
    bool isPrimeDigited(int number){
        int digitCount = 0;
        int initialResult = number;
        while(number > 0){
            number /= 10;
            digitCount++;
        }

        int* digits = getDigitArray(initialResult);
        for(int i = 0; i < digitCount; i++){
            int ch = digits[i];

            if(!isPrimeDigit(ch)){
                return false;
            }
        }
        return true;
    }
    bool isPrimeDigit(int ch){
        switch(ch){
            case 2: return true; break;
            case 3: return true; break;
            case 5: return true; break;
            case 7: return true; break;
            default: return false;
        }
    }
    //Returns the array of digits of an int, most significant digit on the 0 index
    int* getDigitArray(int result) const{
        int digitCount = 0;
        int initialResult = result;
        while(result > 0){
            result /= 10;
            digitCount++;
        }
        int arr[digitCount];
        for(int i = digitCount - 1; i >= 0; i--){
            arr[i] = initialResult % 10;
            initialResult /= 10;
        }
        return &arr[0];
    }
private:
    int primeDigitArray[4] = {2, 3, 5, 7};
};
