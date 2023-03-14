#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class IsomorphicString{
public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2){

        // Your code here
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        unordered_map<char, char> map3;

        this->mapValues(map1, str1);
        this->mapValues(map2, str2);
        this->setCharMap(map3, str1, str2);

        if(str1.size() == str2.size()){
            for(int i = 0; i < str1.size(); i++){
                char ch1 = str1.at(i);
                char ch2 = str2.at(i);
                try{
                    if(map3.at(ch1) != ch2){
                        return false;
                    }
                }
                catch(out_of_range){
                    return false;
                }
            }
        }
        return true;
        /*vector<int> vec1;
        vector<int> vec2;

        for(auto it: map1){
            vec1.push_back(it.second);
        }
        for(auto it: map2){
            vec2.push_back(it.second);
        }*/
        /*
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
    //Maps the characters of each string to each other sequentially with respect to their order
    //If the lengths are different does not operate
    void setCharMap(unordered_map<char, char>& map, string& s, string& x){
        if(s.size() == x.size()){
            for(int i = 0; i < s.size(); i++){
                char ch1 = s.at(i);
                char ch2 = x.at(i);
                if(map.find(ch1) == map.end() && map.find(ch2) == map.end() && !valueExistsInMap(map, ch1) && !valueExistsInMap(map, ch2)){
                    map.insert({ch1, ch2});
                }
            }
        }
    }
    //Returns true if the given char exists as a value in our map
    bool valueExistsInMap(const unordered_map<char, char>& map, char ch){
        for(auto it: map){
            if(it.second == ch){
                return true;
            }
        }
        return false;
    }
    //Function to check if a string is subsequence of other string.
    bool isSubSequence(string A, string B){
        //code here
        int i = 0;
        int j = 0;

        while(i < A.size() && j < B.size()){
            char ch1 = A.at(i);
            char ch2 = B.at(j);
            if(ch1 == ch2){
                i++;
            }
            j++;
        }
        return i == A.size(); // check whether we reached the end of string B which implies completion
        //of checking for the substring
    }
};
