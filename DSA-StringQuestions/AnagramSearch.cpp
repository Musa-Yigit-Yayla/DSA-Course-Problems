#include <string>
#include <vector>
#include <unordered_set>

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
private:
    unordered_set<string> perms;
};
