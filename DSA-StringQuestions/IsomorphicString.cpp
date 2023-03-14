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

        /*vector<int> vec1;
        vector<int> vec2;

        for(auto it: map1){
            vec1.push_back(it.second);
        }
        for(auto it: map2){
            vec2.push_back(it.second);
        }*/

        vector<int> vec3;
        vector<int> vec4;

        for(int i = 0; i < str1.size(); i++){
            char ch = str1.at(i);
            int occurrence = map1.at(ch);
            vec3.push_back(occurrence);
        }
        for(int i = 0; i < str2.size(); i++){
            char ch = str2.at(i);
            int occurrence = map2.at(ch);
            vec4.push_back(occurrence);
        }

        if(vec3.size() == vec4.size()){
            for(int i = 0; i < vec3.size(); i++){
                int curr3 = vec3.at(i);
                int curr4 = vec4.at(i);
                if(curr3 != curr4){
                    return false;
                }
            }
            return true;
        }
        return false;
        /*
        if(vec1.size() == vec2.size()){ // for optimization purposes
            for(int i = 0; i < vec1.size(); i++){
                int curr = vec1.at(i);
                if(count(vec1.begin(), vec1.end(), curr) != count(vec2.begin(), vec2.end(), curr)){
                    return false;
                }
            }
            return true;
        }
        return false;*/
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
