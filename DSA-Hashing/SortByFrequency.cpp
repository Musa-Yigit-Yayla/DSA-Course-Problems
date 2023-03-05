#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
class SortByFrequency{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n){
        //Your code here
        unordered_map<int, int> map;
        vector<int> result;

        for(int i = 0; i < n; i++){
            unordered_map<int, int>::iterator it = map.find(arr[i]);
            int curr = arr[i];
            if(it == map.end()){
                map.insert({curr, 1});
            }
            else{
                it->second++;
            }
        }
        vector<int> usedElements;
        for(int i = 0; i < map.size(); i++){
            int curr = getHighestFreqElt(map, usedElements);
            result.push_back(curr);
        }
        return result;

    }
    //Returns the most frequent element that has not been added to the usedElements yet
    //Before returning the element adds it to the usedElements vector
    //If multiple elements have the same frequency then the biggest one must be returned
    //If no element exists return -1
    int getHighestFreqElt(const unordered_map<int, int>& map, vector<int>& usedElements){
        //Find the biggest frequency in the map by excluding the usedElements
        int max = -1; //max frequency
        for(auto it: map){
            if(it.second > max && count(usedElements.begin(), usedElements.end(), it.first) == 0){
                max = it.second;
            }
        }
        if(max == -1){
            return -1; // all elements are used up apparently
        }
        vector<int> frequentElts;
        for(auto it: map){
            if(it.second == max){
                //this is a frequent elements we are searching for, push it to the vector
                frequentElts.push_back(it.first);
            }
        }
        sort(frequentElts.begin(), frequentElts.end());
        //Store the elements that have that frequency and are not in the usedElements in a separate vector
        int freqElt = frequentElts.at(frequentElts.size() - 1);
        usedElements.push_back(frequentElts.at(freqElt));
        //return the biggest one of those elements
        return(freqElt);
    }
};
