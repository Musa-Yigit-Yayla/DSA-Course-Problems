#include <iostream>
#include <string>
using namespace std;

int number;
string binaryNumber;

int toggleMid(){
    bool isEvenLength = (binaryNumber.size() % 2 == 0);
    if(isEvenLength){
        char ch1 = binaryNumber.at(binaryNumber.size() / 2);
        char ch2 = binaryNumber.at((binaryNumber.size() / 2) - 1);

        if(ch1 == '0'){
            binaryNumber.at(binaryNumber.size() / 2) = '1';
        }
        else{
            binaryNumber.at(binaryNumber.size() / 2) = '0';
        }
        if(ch2 == '0'){
            binaryNumber.at((binaryNumber.size() / 2) - 1) = '1';
        }
        else{
            binaryNumber.at((binaryNumber.size() / 2) - 1) = '0';
        }
    }
    else{
        char ch1 = binaryNumber.at(binaryNumber.size() / 2);
        if(ch1 == '0'){
            binaryNumber.at(binaryNumber.size() / 2) = '1';
        }
        else{
            binaryNumber.at(binaryNumber.size() / 2) = '0';
        }
    }
}
void convertToBinary(int n)
{
    if (n / 2 != 0) {
        convertToBinary(n / 2);
    }
    binaryNumber += (n % 2);
}
int convertToDecimal(){
    int binary = stoi(binaryNumber);
    cout << binary;
    int sum = 0;
    for(int i = 0; i < binaryNumber.size(); i++){
        int currDigit = binary % 10;
        sum += currDigit;
        binary /= 10;
    }
    return sum;
}
int main() {
    int T;
    cin >> T;
    while(T > 0){
        cin >> number;
        convertToBinary(number);
        toggleMid();
        convertToDecimal();
        //cout << convertToDecimal() << endl;
        T--;
    }
	//code
	return 0;
}
