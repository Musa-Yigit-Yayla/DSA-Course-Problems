#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>

using namespace std;
class caseSpecificStringSort{
public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n){
        // your code here
        //Retrieve two strings one containing lowercase chars the other uppercase ones.
        //Subsequently merge the uppercase one to the lowercase one strings

        string uppercaseLetters = "";
        string lowercaseLetters = "";

        for(int i = 0; i < str.size(); i++){
            char ch = str.at(i);
            if(isupper(ch)){
                uppercaseLetters.push_back(ch);
            }
            else{
                lowercaseLetters.push_back(ch);
            }
        }

        vector<int> uppercaseIndexes(uppercaseLetters.size());
        for(int i = 0; i < str.size(); i++){
            char ch = str.at(i);
            if(isupper(ch)){
                uppercaseIndexes.push_back(i);
            }
        }
        sort(uppercaseLetters.begin(), uppercaseLetters.end());
        sort(lowercaseLetters.begin(), lowercaseLetters.end());

        //After having sorted the individual strings, merge them into one.

        string result = "";
        int i = 0, j = 0, k = 0;
        while(i < str.size()){
            if(count(uppercaseIndexes.begin(), uppercaseIndexes.end(), i) != 0){
                //our uppercaseIndexes contains this index
                result += uppercaseLetters.at(j++);
            }
            else{
                result += lowercaseLetters.at(k++);
            }
            i++;
        }
        return result;
    }
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str){
        // Your code here
        unordered_map<char, int> map;
        for(int i = 0; i < str.size(); i++){
            char ch = str.at(i);
            if(map.find(ch) == map.end()){
                map.insert({ch, 1});
            }
            else{
                map.at(ch)++;
            }
        }
        int maxOccurence = 1;
        for(auto it: map){
            if(it.second > maxOccurence){
                maxOccurence = it.second;
            }
        }
        vector<char> maxOccuringChars;
        for(auto it: map){
            if(it.second == maxOccurence){
                maxOccuringChars.push_back(it.first);
            }
        }
        //Traverse the vector, find the smallest one
        char result = maxOccuringChars.at(0);
        for(int i = 1; i < maxOccuringChars.size(); i++){
            char ch = maxOccuringChars.at(i);
            if(ch < result){
                result = ch;
            }
        }
        return result;
    }
};

