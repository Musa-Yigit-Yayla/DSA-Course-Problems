#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class TrapWater {
public:
    int trap(vector<int>& height) {
        //the idea is to search for the first >= wall to our current index i starting from (i + 2)th index
        //then from i + 2 to the first >= wall index found (if found), we will calculate how much water will be trapped
        //if not found we simply continue
        //after calculating the trapped water we add it to the sum and tabulate it using hashmap with a string in format of 1:2 for instance
        //where 1 and 2 represent heights
        //after we calculate one subarray we continue with the remaining part

        int i = 0;
        int totalWater = 0;
        unordered_map<string, int> table;
        while(i < height.size()){
            //i has the left WALL İNDEX
            int leftWall = height.at(i);
            int matchingWallIndex = -1;
            for(int j = i + 2; j < height.size(); j++){
                if(leftWall <= height.at(j)){
                    matchingWallIndex = j;
                    break;
                }
            }
            if(matchingWallIndex != -1){
                //calculate how much water is trapped by first checking our table
                int currWater = 0;
                int matchingWall = height.at(matchingWallIndex);
                string str = stoi(leftWall) + ":" + stoi(matchingWall);
                if(map.find(str) != map.end()){
                    currWater = map.at(str);
                }
                else{
                    //calculate and insert into the table
                    for(int j = i + 1; j < matchingWallIndex; j++){
                        currWater += leftWall - height.at(j);
                        map.insert(make_pair(str, currWater));
                    }
                }
                totalWater += currWater;
            }
        }
        return totalWater;
    }
};
