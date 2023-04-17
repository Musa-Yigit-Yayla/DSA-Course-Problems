#include <string>
#include <unordered_map>

using namespace std;
class LongestDistinctSubstring{
public:
    int getLongestDistinctSubstring(string s){
        int result = 0;
        for(int currLength = 1; currLength <= s.length(); currLength++){
            for(int i = 0; i < s.length() - currLength + 1; i++){
                string currSubstr = s.substr(i, currLength);
                if(this->isAllDistinct(s)){
                    if(currLength > result){
                        result = currLength;
                    }
                }
            }
        }
        return result;
    }
    //Checks whether a given string has all distinct characters
    bool isAllDistinct(string s){
        static unordered_map<char, int> map; //char occurenceCount key value pairs
        for(int i = 0; i < s.size(); i++){
            char ch = s.at(i);
            if(map.find(ch)) == map.end()){
                map.insert({ch, 1});
            }
            else{
                map.at(ch)++;
            }
        }
        for(auto it: map){
            if(it.second > 1){
                map.clear();
                return false;
            }
        }
        map.clear();
        return true;
    }

};
