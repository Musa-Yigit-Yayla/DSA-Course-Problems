#include <unordered_map>
#include <string>

using namespace std;
class AnagramStrings{
public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        if(a.size() == b.size()){
            unordered_map<char, int> map1; //map of a
            unordered_map<char, int> map2; //map of b

            mapValues(a, map1);
            mapValues(b, map2);

            for(auto it: map1){
                if(map2.find(it.first) != map1.end()){
                    if(map2.at(it.first) != map1.at(it.first)){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    void mapValues(string& a, unordered_map<char, int>& map1){
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
