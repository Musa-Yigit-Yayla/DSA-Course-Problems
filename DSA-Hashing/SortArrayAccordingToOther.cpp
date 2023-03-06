#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
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

            stringstream ss;
            ss << "" << indexOf << "," << occurenceCount;
            string s = ss.str();
            myMap.insert({curr, s});

        }

        int insertionIndex = 0;
        //Traverse the map
        /*for(auto it: map){
            int indexOf = it.first;
            int* arr = getValueAndCount(it.second);
            int value = *(arr);
            int occurenceCount = *(arr++);


            for(int i = 0; i < occurenceCount; i++){

                insertionIndex++;
            }
        }*/
        for(int i = 0; i < A2.size(); i++){
            int curr = A2.at(i);
            unordered_map<int, string>::iterator it = myMap.find(curr);
            vector<int> arr = getIndexOfAndCount(it->second);
            int indexOf = arr[0];
            int occurenceCount = arr[1];

            for(int i = 0; i < occurenceCount && insertionIndex < A1.size(); i++){

                //swap the element at the insertionIndex with the indexOf element
                //remove the element at insertionIndex and insert the indexOf element's value to that index
                A1.erase(A1.begin() + insertionIndex);
                A1.insert(A1.begin() + insertionIndex, curr);
                insertionIndex++;
            }
        }

        //Erase the elements after insertionIndex in A1
        A1.erase(A1.begin() + insertionIndex, A1.end());
        //Append the unused elements in initialA1 in sorted order to A1
        sort(initialA1.begin(), initialA1.end());
        for(int i = 0; i < initialA1.size(); i++){
            A1.push_back(initialA1.at(i));
        }

        return A1;
    }
    //Returns the first occurence of the element
    int getIndexOf(int elt, const vector<int>& a){
        int index = -1;
        for(int i = 0; i < a.size(); i++){
            if(a.at(i) == elt){
                return i;
            }
        }
        return index;
    }
    //returns the indexOf and the occurence count of an element in the a1 which is also included in a2
    vector<int> getIndexOfAndCount(string s){
        //might be problematic !!
        int commaIndex = s.find(",", 0);
        string s1 = s.substr(0, commaIndex);
        string s2 = s.substr(commaIndex + 1);
        int val1 = stoi(s1);
        int val2 = stoi(s2);
        vector<int> result({val1, val2});
        return result;
    }
    //removes the given target from the arr if
    void remove(int target, vector<int>& arr){
        arr.erase(std::remove(arr.begin(), arr.end(), target), arr.end());
    }
};
