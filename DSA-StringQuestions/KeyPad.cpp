#include <string>

using namespace std;

string getDigit(char);

//Function to find matching decimal representation of a string as on the keypad.
string printNumber(string s, int n) {
    //code here
    string value;

    for(int i = 0; i < s.size(); i++){
        value += getDigit(s.at(i));
    }
    return value;
}
string getDigit(char ch){
    switch(ch){
        case 'a': return "" + to_string(2); break;
        case 'b': return "" + to_string(2); break;
        case 'c': return "" + to_string(2); break;

        case 'd': return "" + to_string(3); break;
        case 'e': return "" + to_string(3); break;
        case 'f': return "" + to_string(3); break;

        case 'g': return "" + to_string(4); break;
        case 'h': return "" + to_string(4); break;
        case 'i': return "" + to_string(4); break;

        case 'j': return "" + to_string(5); break;
        case 'k': return "" + to_string(5); break;
        case 'l': return "" + to_string(5); break;

        case 'm': return "" + to_string(6); break;
        case 'n': return "" + to_string(6); break;
        case 'o': return "" + to_string(6); break;

        case 'p': return "" + to_string(7); break;
        case 'q': return "" + to_string(7); break;
        case 'r': return "" + to_string(7); break;
        case 's': return "" + to_string(7); break;

        case 't': return "" + to_string(8); break;
        case 'u': return "" + to_string(8); break;
        case 'v': return "" + to_string(8); break;

        case 'w': return "" + to_string(9); break;
        case 'x': return "" + to_string(9); break;
        case 'y': return "" + to_string(9); break;
        case 'z': return "" + to_string(9); break;

        default: return "" + ch; break;

    }
}

