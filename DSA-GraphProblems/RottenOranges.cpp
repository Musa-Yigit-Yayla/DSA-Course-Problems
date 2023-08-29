#include <vector>
#include <climits>

using namespace std;
class RottenOranges{
private:
    vector<vector<vector<int>>> adjList; //contains adjacency list disregarding empty cells
    int columnCount;
    //the 3d vector data field contains a 2d vector which is the adjacency list of every non empty cell
    //which ultimately contains the index of the element at the innermost vector as the 0th element
    //and the element type in the first index
    int linearLength;
public:
    //Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        //0 for empty cell 1 for fresh orange 2 for rotten orange
        //initialize the adjList
        this->columnCount = grid.at(0).size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < columnCount; j++){
                int currIndex = columnCount * i + j;
                int currValue = grid.at(i).at(j);
                vector<vector<int>> curr;
                vector<int> currInnerVec;
                currInnerVec.push_back(currIndex);
                currInnerVec.push_back(currValue);
                curr.push_back(currInnerVec);
                this->adjList.push_back(curr);
            }
        }
        bool visit[grid.size() * columnCount];
        int minTime[grid.size() * columnCount];
        this->linearLength = grid.size() * columnCount;
        for(int i = 0; i < grid.size() * columnCount; i++){
            visit[i] = false;
            minTime[i] = INT_MAX;
        }
        //for each and every 1 in our map invoke findTime
        int returnValue = -1;
        for(int i = 0; i < this->adjList.size(); i++){
            vector<vector<int>> currAdj = this->adjList.at(i);
            int currIndex = currAdj.at(0).at(0);
            int currValue = currAdj.at(0).at(1);
            if(currValue == 1){
                this->findTime(currIndex, -1, minTime, 0, visit);
                int currResult = minTime[currIndex];
                if(currResult > returnValue){
                    returnValue = currResult;
                }
            }
        }
        return returnValue;
    }
    //Finds the minimum time required for a fresh orange to rot
    void findTime(const int startVertex, int currVertex, int minTime[], int currTime, bool visited[]){
        //cout << "Visiting: (" << to_string(currVertex / columnCount) << ", " << to_string(currVertex % columnCount) << "), currTime: " << to_string(currTime) << endl;
        visited[currVertex] = true;
        if(currVertex == -1){
            //start of the recursion
            vector<vector<int>> currAdj = this->adjList.at(startVertex);
            for(int i = 0; i < currAdj.size(); i++){
                int currAdjValue = currAdj.at(i).at(1);
                int currAdjIndex = currAdj.at(i).at(0);
                if(currAdjValue == 1 && !visited[currAdjIndex]){
                    findTime(startVertex, currAdjIndex, minTime, currTime + 1, visited);
                }
                else if(currAdjValue == 2){
                    if(minTime[startVertex] > currTime + 1){
                        minTime[startVertex] = currTime + 1;
                    }
                }
            }
        }
        else{
            if(currVertex == 1){
                vector<vector<int>> currAdj = this->adjList.at(currVertex);
                for(int i = 0; i < currAdj.size(); i++){
                    int currAdjValue = currAdj.at(i).at(1);
                    int currAdjIndex = currAdj.at(i).at(0);
                    if(currAdjValue == 1 && currAdjIndex != startVertex && !visited[currAdjIndex]){ //second logic allows us to avoid
                    //infinite recursion if there exists a cycle of 1s in our graph
                        findTime(startVertex, currAdjIndex, minTime, currTime + 1, visited);
                    }
                    else if(currAdjValue == 2){
                        if(minTime[startVertex] > currTime + 1){
                            minTime[startVertex] = currTime + 1;
                        }
                    }
                }
            }
            else if(currVertex == 2){
                if(minTime[startVertex] > currTime + 1){
                    minTime[startVertex] = currTime + 1;
                }
            }
        }
        visited[startVertex] = false; //reset for bakctracking
    }
};
