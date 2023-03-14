#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution{
public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2){

        // Your code here
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        this->mapValues(map1, str1);
        this->mapValues(map2, str2);

        vector<int> vec1;
        vector<int> vec2;

        for(auto it: map1){
            vec1.push_back(it.second);
        }
        for(auto it: map2){
            vec2.push_back(it.second);
        }

        if(vec1.size() == vec2.size()){ // for optimization purposes
            for(int i = 0; i < vec1.size(); i++){
                int curr = vec1.at(i);
                if(count(vec1.begin(), vec1.end(), curr) != count(vec2.begin(), vec2.end(), curr)){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    void mapValues(unordered_map<char, int>& map1, const string& str1){
        for(int i = 0; i < str1.size(); i++){
            char ch = str1.at(i);
            if(map1.find(ch) == map1.end()){
                map1.insert({ch, 1});
            }
            else{
                map1.at(ch)++;
            }
        }
    }
};
