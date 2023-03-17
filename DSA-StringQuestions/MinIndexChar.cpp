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
    //Function to find minimum number of characters which Ishaan must insert
    //such that string doesn't have three consecutive same characters.
    int modified (string s){
        // Your code here
        int consecCount = 1;
        char prevChar = s.at(0);
        char maxChar = prevChar;
        int maxConsecCount = 1;
        vector<int> maxConsecCounts;
        bool consecCharFound = false;
        for(int i = 1; i < s.size(); i++){
            char ch = s.at(i);
            if(!consecCharFound){
                if(prevChar == ch){
                    consecCount++;

                }
                else{
                    if(consecCount >= 3){
                        maxConsecCounts.push_back(consecCount);
                    }
                    consecCount = 1;
                    prevChar = ch;
                }
                if(consecCount > maxConsecCount){
                    maxConsecCount = consecCount;
                }
            }
            if(ch > maxChar){
                maxChar = ch;
            }

        }
        int sum = 0;
        for(int i = 0; i < maxConsecCounts.size(); i++){
            int curr = maxConsecCounts.at(i);
            cout << curr;
            sum += ceil(curr / 2.0) - 1;
        }
        return sum;
    }
};
