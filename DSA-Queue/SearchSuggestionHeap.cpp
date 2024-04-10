//Leetcode problem

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //for each substring of the searchword (starting from index 0 at all times) we search for matchs in products
        //we accumulate the matched entries and pick the first three in lexicographic order
        vector<vector<string>> result;
        this->heapSort(products);
        for(int i = 1; i < searchWord.size(); i++){
            string searchKey = searchWord.substr(0, i + 1);
            vector<string> matchedEntries;
            for(int j = 0; j < products.size(); j++){
                string currProduct = products.at(j);
                if(currProduct.starts_with(searchKey)){
                    //insert the current product to matchedEntries
                    matchedEntries.push_back(currProduct);
                    if(matchedEntries.size() == 3){
                        break;
                    }
                }
            }
            result.push_back(matchedEntries);
        }
        return result;
    }
    //Uses max heap
    void heapSort(vector<string>& arr){
        //build heap
        //start from the last nonleaf node and keep building a heap until root index (inclusive), since leaf nodes satisfy heap property
        //O(n)
        for(int i = floor(arr.size() / 2); i >= 0; i--){
            this->heapify(arr, i, arr.size() - 1);
        }
        //next keep extracting root element to form a sorted array
        for(int i = arr.size() - 1; i > 0; i++){
            swap(arr.at(i), arr.at(0));
            this->heapify(arr, 0, i - 1);
        }
    }
    //lastIndex is inclusive careful!
    void heapify(vector<string>& arr, int rootIndex, int lastIndex){
        //float the root element down into its correct index
        int currIndex = rootIndex;
        int leftIndex = 2 * currIndex + 1;
        int rightIndex = 2 * currIndex + 2;

        while(currIndex <= lastIndex && leftIndex <= lastIndex){
            //we are guaranteed to have a left child
            string largerChild = arr.at(leftIndex);
            int largerIndex = leftIndex;
            if(rightIndex < arr.size() && arr.at(rightIndex) > largerChild){
                largerChild = arr.at(rightIndex);
                largerIndex = rightIndex;
            }
            if(largerChild > arr.at(currIndex)){
                //swap the current element with its larger child
                swap(arr.at(currIndex), arr.at(largerIndex));
                currIndex = largerIndex;
                leftIndex = 2 * currIndex + 1;
                rightIndex = 2 * currIndex + 2;
            }
            else{
                //root element is at its correct position
                break;
            }
        }
    }
};
