#include <unordered_map>
#include <string>

using namespace std;
class MinIndexChar{
  public:
    //Function to find the minimum indexed character.
    int minIndexCharacter(string str, string patt){
        // Your code here
        unordered_map<char, int> map1; // char occurence count key value pairs
        unordered_map<char, int> map2;

        for(int i = 0; i < str.size(); i++){
            char ch = str.at(i);
            if(map1.find(ch) == map1.end()){
                map1.insert({ch, 1});
            }
            else{
                map1.at(ch)++;
            }
        }
        for(int i = 0; i < patt.size(); i++){
            char ch = patt.at(i);
            if(map2.find(ch) == map2.end()){
                map2.insert({ch, 1});
            }
            else{
                map2.at(ch)++;
            }
        }
        for(int i = 0; i < str.size(); i++){
            char ch = str.at(i);
            if(map1.find(ch) != map1.end() && map2.find(ch) != map2.end()){
                return i;
            }
        }
        return -1;
    }
};
