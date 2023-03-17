/*
*Program to reverse given words in a string, separated by dots
*Musa Yiğit Yayla
*/
class Solution{
public:
    //Function to reverse words in a given string.
    string reverseWords(string s){
        // code here
        stack<string> myStack;
        vector<string> vec;

        string word = "";
        for(int i = 0; i < s.size(); i++){
            char ch = s.at(i);
            if(ch != '.'){
                word += ch;
            }
            else{
                reverseString(word);
                vec.push_back(word);
                if(i != s.size() - 1){
                    word = "";
                }
            }
        }
        //Reverse the word beforehand, might be problematic
        reverseString(word);
        vec.push_back(word);

        string totalString = "";
        for(int i = 0; i < vec.size(); i++){
            string curr = vec.at(i);
            if(i != vec.size() - 1){
                curr += '.';
            }
            totalString += curr;
        }
        reverseString(totalString);
        return totalString;
    }
    //Reverses the string by its middle point and assigns new string's reference to ours
    void reverseString(string& s){
        int low = 0;
        int high = s.size() - 1;
        string newS = "";
        while(low < high){
            newS += s.at(high);

            low++;
            high--;
        }
        while(high >= 0){
            newS += s.at(high);

            high--;
        }
        s = newS;
    }
};
