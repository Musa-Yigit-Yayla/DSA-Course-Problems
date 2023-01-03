#include <vector>

using namespace std;

class RopeCutting{
public:
    //Returns the max number of pieces this rope can be cut into the length of the given elements in the vector
    int cutRope(int rope, vector<int>& lengths){
        return cutRopeHelper(rope, lengths, 5);
    }
    int cutRopeHelper(int rope, vector<int>& lengths, int noOfPieces){
        bool isCuttable = true;
        for(int i = 0; i < lengths.size(); i++){
            //check whether our rope is smaller for each element
            if(lengths.at(i) <= rope){
                break;
            }
            else if(i == lengths.size() - 1){
                isCuttable = false;
            }
        }
        if(rope == 0){
            return noOfPieces; // base case
        }
        else if(!isCuttable){
            return -1; // base case
        }
        //int lengthsSize = lengths.size();
        vector<int> results;
        for(size_t i = 0; i < lengths.size(); i++){
            //Try to cut into each piece one by one recursively
            int currLengthToCut = lengths.at(i);
            results.push_back(cutRopeHelper(rope - currLengthToCut, lengths, noOfPieces + 1));
        }
        //return the max of the results
        int maxer = results.at(0);
        for(int i = 1; i < results.size(); i++){
            int* curr = &results.at(i);
            if(*curr > maxer){
                maxer = *curr;
            }
        }
        return maxer;
    }
};
