#include <string>

using namespace std;

//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x){
     //Your code here
     char ch = x.at(0);
     int currCharIndex = 0;
     int result = -1;
     int prevResult = -1;

     for(int i = 0; i < s.size() && currCharIndex <= x.size(); i++){
         if(currCharIndex == x.size()){
             //reset the ch, searching again
             ch = x.at(0);
             currCharIndex = 0;
             result = prevResult;
         }
         char curr = s.at(i);
         if(ch == curr){
             if(curr == x.at(0)){
                result = i; //assuming this is the beginning of our subsequence
             }
             ch = x.at(++currCharIndex);
         }
         else{
             //no such subsequence reset the properties
             currCharIndex = 0;
             ch = x.at(currCharIndex);
             result = prevResult;
         }
     }

     return result;
}
