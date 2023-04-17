#include <string>
#include <vector>
#include <unordered_set>
#include <ctype.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

class AnagramSearch{
public:
    bool anagramSearch(string s, string pattern){
        perms.clear();

        vector<string> patternPerms = findPermutations(pattern);
        for(int i = 0; i < patternPerms.size(); i++){
            string currSubstr = patternPerms.at(i);
            if(s.find(currSubstr) != string::npos){
                return true;
            }
        }
        return false;
    }
    vector<string> findPermutations(string s){
        vector<string> result;
        permHelper(s, "");
        for(auto it: perms){
            result.push_back(it);
        }
        return result;
    }
    void permHelper(string s, string usedChars){ //index to add chars from
        if(usedChars.length() == s.length()){
            //base case
            this->perms.insert(usedChars);
        }
        else{
            for(int i = 0; i < s.length(); i++){
                char ch = s.at(i);
                if(usedChars.find(ch) == string::npos){ //ch does not exist in usedChars which means that we can use it now
                    permHelper(s, usedChars + ch);

                }
            }
        }
    }
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        // your code here
        unordered_map<char, bool> charOccurence;
        this->setCharOccurence(charOccurence);
        string strCopy = str;
        transform(strCopy.begin(), strCopy.end(), strCopy.begin(), ::tolower);
        for(int i = 0; i < strCopy.size(); i++){
            char curr = strCopy.at(i);
            if(isalpha(curr)){
                charOccurence.at(strCopy.at(i)) = true;
            }
        }
        //check if we have each and every occurence of all English alphabet chars
        for(auto it: charOccurence){
            if(it.second == false){
                return false;
            }
        }
        return true;
    }
    //given input is assumed to be empty unordered_map
    void setCharOccurence(unordered_map<char, bool>& charOccurence){
        charOccurence.insert({'a', false});
        charOccurence.insert({'b', false});
        charOccurence.insert({'c', false});
        charOccurence.insert({'d', false});
        charOccurence.insert({'e', false});
        charOccurence.insert({'f', false});
        charOccurence.insert({'g', false});
        charOccurence.insert({'h', false});
        charOccurence.insert({'i', false});
        charOccurence.insert({'j', false});
        charOccurence.insert({'k', false});
        charOccurence.insert({'l', false});
        charOccurence.insert({'m', false});
        charOccurence.insert({'n', false});
        charOccurence.insert({'o', false});
        charOccurence.insert({'p', false});
        charOccurence.insert({'q', false});
        charOccurence.insert({'r', false});
        charOccurence.insert({'s', false});
        charOccurence.insert({'t', false});
        charOccurence.insert({'u', false});
        charOccurence.insert({'v', false});
        charOccurence.insert({'w', false});
        charOccurence.insert({'x', false});
        charOccurence.insert({'y', false});
        charOccurence.insert({'z', false});
    }
private:
    unordered_set<string> perms;
};
