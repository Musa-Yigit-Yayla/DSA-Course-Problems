#include <string>
#include <unordered_map>

using namespace std;
class FindRank{
public:
    int findRank(string s){
         //Your code here
        unordered_map<char, int> occurences;
        for(int i = 0; i < s.size(); i++){
            char ch = s.at(i);

            occurences[ch]++;
            if(occurences.at(ch) > 1){
                return 0;
            }
        }
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            int counter = getNoOfBiggerChars(s, i);
            result += ((factorial(s.size() - i - 1)) * counter);
        }
        return result + 1;
    }
    int factorial(int n){
        int result = 1;
        while(n > 0){
            result *= n;
            n--;
        }
        return result;
    }
    int getNoOfBiggerChars(string s, int fromIndex){
        char ch = s.at(fromIndex);
        int counter = 0;
        for(int i = fromIndex + 1; i < s.size(); i++){
            char curr = s.at(i);
            if(ch > curr){
                counter++;
            }
        }
        return counter;
    }

};
