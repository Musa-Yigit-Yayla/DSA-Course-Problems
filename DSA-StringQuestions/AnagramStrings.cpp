#include <unordered_map>
#include <string>

using namespace std;
class AnagramStrings{
public:
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2){
        // Your code here
        string initialS1 = s1;

        unordered_map<char, int> map1; //char occurence count key value pairs
        unordered_map<char, int> map2;

        mapValues(s1, map1);
        mapValues(s2, map2);

        removeChars(s1, s2, map2);
        removeChars(s2, initialS1, map1);

        if(s1.size() == 0 && s2.size() == 0){
            return "-1";
        }
        else{
            return s1 + s2;
        }

    }
    /*void removeChars(string& s1, string s2){
        string newS1 = "";
        for(int i = 0; i < s1.size(); i++){
            char ch = s1.at(i);
            if(count(s2.begin(), s2.end(), ch) == 0){
                newS1 += ch;
            }
        }
        s1 = newS1;
    }*/
    //Add the chars in s1 which do not occur in s2 into an empty string
    void removeChars(string& s1, string s2, const unordered_map<char, int>& map2){
        string newS1;

        for(int i = 0; i < s1.size(); i++){
            char ch = s1.at(i);
            if(map2.find(ch) == map2.end()){
                newS1 += ch;
            }
        }
        s1 = newS1;
    }
    void mapValues(const string& a, unordered_map<char, int>& map1){
        for(int i = 0; i < a.size(); i++){
            char ch = a.at(i);
            if(map1.find(ch) == map1.end()){
                map1.insert({ch, 1});
            }
            else{
                map1.at(ch)++;
            }
        }
    }

};
