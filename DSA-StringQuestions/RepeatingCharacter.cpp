#include <string>
#include <unordered_map>

using namespace std;
class RepeatingCharacter{
public:
    //Function to find repeated character whose first appearance is leftmost.
    int repeatedCharacter(string s){
        //Your code here
        unordered_map<char, int> map;
        for(int i = 0; i < s.size(); i++){
            char ch = s.at(i);
            if(map.find(ch) == map.end()){
                //we already coincided with this element, so return the index
                map.insert({ch, 1});
            }
            else{
                map.at(ch)++;
            }
        }

        for(int i = 0; i < s.size(); i++){
            char ch = s.at(i);
            if(map.find(ch) != map.end() && map.at(ch) != 1){
                return i;
            }
        }
        return -1;
    }

    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s){
       //Your code here
       unordered_map<char, int> map; // map to count the frequencies of our characters
       for(int i = 0; i < s.size(); i++){
           char ch = s.at(i);
           if(map.find(ch) == map.end()){
               map.insert({ch, 1});
           }
           else{
               map.at(ch)++;
           }
       }
       for(int i = 0; i < s.size(); i++){
           char ch = s.at(i);
           if(map.at(ch) == 1){
               return ch;
           }
       }
       return '$';
    }
};
