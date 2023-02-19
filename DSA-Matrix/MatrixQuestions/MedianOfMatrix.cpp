#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MedianOfMatrix{
public:
    /*
    Returns the median of the given matrix
    r represents row count
    c represents column count
    */
    int getMedian(vector<vector<int>>& vec, int r, int c){
        vector<int> container;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                container.push_back(vec[i][j]);
            }
        }
        sort(container.begin(), container.end());

        return container.at(container.size() / 2);
    }

};
