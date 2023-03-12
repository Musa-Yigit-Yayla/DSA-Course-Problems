#include <unordered_set>

using namespace std;

class LongestConsequtiveSubsequence{
public:
    //Returns the length of the longest subsequence which is consequtive
    int longestSubsequence(int arr[], int n){
        //First hash the arr elements into a set
        unordered_set<int> set;

        for(int i = 0; i < n; i++){
            set.insert(arr[i]);
        }

        unordered_set<int>::iterator it = set.begin();
        bool searchingUpwards = false;
        //int subsequenceBegin = 0;
        int result = 1;
        int currResult = 1;
        while(it != set.end()){
            if(set.find(*(it) - 1) != set.end() && !searchingUpwards){
                it = set.find(*(it) - 1);
                //subsequenceBegin = it - set.begin();
            }
            else if(set.find(*(it) + 1) != set.end()){
                it = set.find(*(it) + 1);
                currResult++;
                result = max(result, currResult);
                searchingUpwards = true;
            }
            else{

                if(set.find(*(it) -1) != set.end()){
                   it = set.find(*(it) - 1);
                }
                else if(set.find(*(it) + 1) != set.end()){
                    it = set.find(*(it) + 1);
                }
                else{
                    it = set.end();
                }
                searchingUpwards = false;
                currResult = 1;
            }
        }
        return result;
    }
    //Function to return length of longest subsequence of consecutive integers.
    //Efficient approach
    int findLongestConseqSubseq(int arr[], int n){
      //Your code here
      unordered_set<int> set;
      for(int i = 0; i < n; i++){
          set.insert(arr[i]);
      }
      int result = 1;
      int maxResult = 1;

      for(auto it: set){
        if(set.find(it - 1) == set.end()){
            int curr = 1;
            while(set.find(it + curr) != set.end()){
                curr++;
            }
            result = max(result, curr);
        }
      }
      return result;
    }
};
