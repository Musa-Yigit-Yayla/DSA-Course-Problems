#include <unordered_set>
#include <vector>

using namespace std;
class CountNonRepeatedElts{
public:
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
        vector<int> arr2;
        /*for(int i = 0; i < map.size(); i++){
            int* arr2 = getHighestFreqElt(map, usedElements);
            int freqElt = arr2[0];
            result.push_back(curr);
        }*/
        do{
            arr2 = getHighestFreqElt(map, usedElements);
            //if(arr2 != ){
                int freqElt = arr2.at(0);
                int frequency = arr2.at(1);
                //cout << "freqElt: " << freqElt << " frequency: " << frequency << endl;
                for(int i = 0; i < frequency; i++){
                    result.push_back(freqElt);
                }
            //}
        }while(arr2.at(0) != -1);

        return result;
    }
    //Returns the most frequent element and its frequency consecutively as an array that has not been added to the usedElements yet
    //Before returning the element adds it to the usedElements vector
    //If multiple elements have the same frequency then the smallest one must be returned
    //If no element exists return {-1, -1}
    vector<int> getHighestFreqElt(const unordered_map<int, int>& map, vector<int>& usedElements){
        //Find the biggest frequency in the map by excluding the usedElements
        int max = -1; //max frequency
        int counter = 0;
        vector<int> frequentElts; //contains the elements with the highest frequency that hasn't been used yet
        for(auto it: map){
            if(it.second >= max && count(usedElements.begin(), usedElements.end(), it.first) == 0){
                max = it.second;
                frequentElts.push_back(it.first);
                counter++;
            }
        }
        if(counter == 0){

            vector<int> vec({-1, -1});
            return vec;
        }
        //retrieve the smallest frequent elt
        sort(frequentElts.begin(), frequentElts.end());
        int freqElt;
        freqElt = frequentElts.at(0);
        usedElements.push_back(freqElt);

        //return the biggest one of those elements
        vector<int> arr({freqElt, max});
        return(arr);
    }
    //Returns the greatest frequency excluding the usedElements
    //Returns -1 if no candidate found
    int getGreatestFrequency(const unordered_map<int, int>& map, const vector<int>& usedElements){
        int max = -1;
        for(auto it: map){
            if(it.second > max && count(usedElements.begin(), usedElements.end(), it.first) == 0){
                max = it.second;;
            }
        }
        return max;
    }
};
