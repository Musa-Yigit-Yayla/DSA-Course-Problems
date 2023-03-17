/*
*Program to reverse given words in a string, separated by dots
*Musa Yiğit Yayla
*/
class ReverseWords{
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
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2){
        // Your code here
        string initialS1 = s1;

        removeChars(s1, s2);
        removeChars(s2, initialS1);

        if(s1.size() == 0 && s2.size() == 0){
            return "-1";
        }
        else{
            return s1 + s2;
        }

    }
    void removeChars(string& s1, string s2){
        string newS1 = "";
        for(int i = 0; i < s1.size(); i++){
            char ch = s1.at(i);
            if(count(s2.begin(), s2.end(), ch) == 0){
                newS1 += ch;
            }
        }
        s1 = newS1;
    }
};
