#include <string>
#include <iostream>

using namespace std;
class PrintPyramid{
public:
    //prints the string in a pyramid form
    void printPyramid(string s, int n){
        string emptyString = "";
        for(int i = 0; i < s.size(); i++){
            emptyString += " ";
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j >= n / 2 - i && j <= n / 2 + i){
                    cout << s;
                }
                else{
                    cout << emptyString;
                }
            }
            cout << endl;
        }
    }
    //print the string in heart shape
    //
    void printHeart(){
        string s = "";

        s += "       ****            ****\n";
        s += "      *******        ********\n";
        s += "     **********    ***********\n";
        s += "    ************ **************\n";
        s += "   *****************************\n";
        s += "  ************Aybuke*************\n";
        s += "  *******************************\n";
        s += "   *****************************\n";
        s += "    ***************************\n";
        s += "     *********Yigit***********\n";
        s += "      ***********************\n";
        s += "       *********************\n";
        s += "        *******************\n";
        s += "         *****************\n";
        s += "          ***************\n";
        s += "           *************\n";
        s += "            ***********\n";
        s += "             *********\n";
        s += "              *******\n";
        s += "               *****\n";
        s += "                ***\n";

        string s1 = "";

        const char heart = 3;
        for(int i = 0; i < s.size(); i++){
            char ch = s.at(i);
            if(s.at(i) == '*'){
                s1 += heart;
            }
            else{
                s1 += ch;
            }
        }
        cout  << s1 << endl;
    }
};
