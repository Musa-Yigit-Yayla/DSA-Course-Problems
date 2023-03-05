#include <unordered_set>
#include <vector>

using namespace std;
class CountNonRepeatedElts{
public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n){
        //Your code here
        unordered_map<int, int> map;
        vector<int> result;

        for(int i = 0; i < n; i++){
            unordered_map<int, int>::iterator it = map.find(arr[i]);
            if(it == map.end()){
                map.insert({arr[i], 1});
            }
            else{
                it->second++;
            }
        }
        vector<int> usedElements;
        int* arr2 = &arr[0]; // just to save the pointer from having a garbage value
        /*for(int i = 0; i < map.size(); i++){
            int* arr2 = getHighestFreqElt(map, usedElements);
            int freqElt = arr2[0];
            result.push_back(curr);
        }*/
        do{
            arr2 = getHighestFreqElt(map, usedElements);
            if(arr2 != nullptr){
                int freqElt = arr2[0];
                int frequency = arr2[1];
                for(int i = 0; i < frequency; i++){
                    result.push_back(freqElt);
                }
            }
        }while(arr2 != nullptr);

        return result;
    }
    //Returns the most frequent element and its frequency consecutively as an array that has not been added to the usedElements yet
    //Before returning the element adds it to the usedElements vector
    //If multiple elements have the same frequency then the smallest one must be returned
    //If no element exists return nullptr
    int* getHighestFreqElt(const unordered_map<int, int>& map, vector<int>& usedElements){
        //Find the biggest frequency in the map by excluding the usedElements
        int max = -1; //max frequency
        for(auto it: map){
            if(it.second > max && count(usedElements.begin(), usedElements.end(), it.first) == 0){
                max = it.second;
            }
        }
        if(max == -1){
            return nullptr; // all elements are used up apparently
        }
        vector<int> frequentElts;
        int freqElt;
        for(auto it: map){
            if(it.second == max){
                //this is a frequent elements we are searching for
                freqElt = it.first;
                break;
            }
        }

        usedElements.push_back(freqElt);
        //return the biggest one of those elements
        int arr[2] = {freqElt, max};
        return(arr);
    }
};
