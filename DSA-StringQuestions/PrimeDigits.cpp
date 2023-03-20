#include <string>

using namespace std;
class PrimeDigits{
public:
    //Function to find nth number made of only prime digits.
    int primeDigits(int n){
        //code here
        int result = 2;
        int counter = 1;

        while(counter <= n){
            string s = "" + result;
            if(isPrimeDigited(s)){
                counter++;
            }
            result++;
        }
        return result;
    }
    bool isPrimeDigited(const string& s){
        for(int i = 0; i < s.size(); i++){
            char ch = s.at(i);
            if(!isPrimeDigit(ch)){
                return false;
            }
        }
        return true;
    }
    bool isPrimeDigit(char ch){
        switch(ch){
            case '2': return true; break;
            case '3': return true; break;
            case '5': return true; break;
            case '7': return true; break;
            default: return false;
        }
    }
private:
    int primeDigitArray[4] = {2, 3, 5, 7};
};
