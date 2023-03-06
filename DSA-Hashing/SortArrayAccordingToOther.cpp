#include <unordered_map>
#include <algorithm>
#include <string>

class SortArrayAccordingToOther{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]

    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int>& A1, int N, const vector<int>& A2, int M) {
        //Your code here
        vector<int> result;
        vector<int> initialA1(A1);

        unordered_map<int, string> myMap;
        for(int i = 0; i < A2.size(); i++){


            int curr = A2.at(i);
            int occurenceCount = count(A1.begin(), A1.end(), curr);
            int indexOf = getIndexOf(curr, A2); //indexOf curr in the A2 will be used as the key in map

            remove(curr, initialA1);
            string s = "" + curr + "," + occurenceCount;
            myMap.insert({indexOf, s});

        }

        int insertionIndex = 0;
        //Traverse the map
        for(auto it: map){
            int indexOf = it.first;
            int* arr = getValueAndCount(it.second);
            int value = *(arr);
            int occurenceCount = *(arr++);


            for(int i = 0; i < occurenceCount; i++){

                insertionIndex++;
            }
        }
    }
    //Returns the first occurence of the element
    int getIndexOf(int elt, const vector<int>& a){
        int index = -1;
        for(int i = 0; i < a.size(); i++){
            if(a.at(i) == elt){
                index = i;
            }
        }
        return index;
    }
    //returns the value and the occurence count of an element in the a1 which is also included in a2
    int* getValueAndCount(string s){
        //might be problematic !!
        int commaIndex = s.find(",", 0);
        string s1 = s.substr(0, commaIndex);
        string s2 = s.substr(commaIndex + 1);
        int arr[2] = {stoi(s1), stoi(s2)};
        return arr;
    }
    //removes the given target from the arr if
    void remove(int target, vector<int>& arr){
        arr.erase(std::remove(arr.begin(), arr.end(), target), arr.end());
    }
};
