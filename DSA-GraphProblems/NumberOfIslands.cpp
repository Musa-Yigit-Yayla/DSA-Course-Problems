#include <vector>

using namespace std;
class NumberOfIslands{
  private:
    vector<vector<int>> adjList;
  public:

    const int charValue0 = 48; //in decimal
    const int charValue1 = 49; //in decimal
    // Function to find the number of islands.
    //Passed grid must not be empty and not ragged
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        //initialize the adjList so that we have it full of empty vectors with number of grid elements
        int gridElementCount = grid.size() * grid.at(0).size();
        for(int i = 0; i < gridElementCount; i++){
            vector<int> vec;
            this->adjList.push_back(vec);
        }
        //create a graph which is undirected and unweighted using adj list
        //we must also count the number of vertices and give them values according to their grid pos
        int rowLength = grid.at(0).size();
        int gridLength = grid.size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < rowLength; j++){
                int currLabel = this->getLabel(i, j, rowLength, gridLength, grid);
                //retrieve the adjacent nodes with their label
                vector<int> adjNodes = this->getAdjNodes(i, j, rowLength, gridLength, grid);
                this->adjList.at(currLabel) = adjNodes;
            }
        }

        //subsequently we must count the number of connected graphs and return it as the result
        //to do this we need to traverse each and every graph node, once we cannot go to anywhere
        //we must traverse other nodes which are not connected to the graph that we have just traversed


        //notice that we regard diagonally adjacent nodes connected as well
    }
    int getLabel(int row, int column, const int rowLength){
        return row * rowLength + column + 1; //we start counting from 1
    }
    //Returns the adjacent nodes if any
    vector<int> getAdjNodes(int row, int column, const int rowLength, gridLength, vector<vector<char>>& grid){
        vector<int> result;
        //start from top left
        int currRow = row - 1;
        int currColumn = column - 1;
        if(currRow >= 0){
            if(currColumn >= 0){
                int ch = grid.at(currRow).at(currColumn);
                if(ch == charValue1){
                    result.push_back(this->getLabel(currRow, currColumn, rowLength));
                }
            }
            currColumn = column;
            int ch = grid.at(currRow).at(currColumn);
            if(ch == charValue1){
                result.push_back(this->getLabel(currRow, currColumn, rowLength));
            }
            currColumn = column + 1;
            if(currColumn < rowLength){
                int ch = grid.at(currRow).at(currColumn);
                if(ch == charValue1){
                    result.push_back(this->getLabel(currRow, currColumn, rowLength));
                }
            }
        }
        currRow = row;
        currColumn = column - 1;
        if(currColumn >= 0){
            int ch = grid.at(currRow).at(currColumn);
            if(ch == charValue1){
                result.push_back(this->getLabel(currRow, currColumn, rowLength));
            }
        }
        //disregard the piece's position itself since we use adjList
        currColumn = column + 1;
        if(currColumn < rowLength){
            int ch = grid.at(currRow).at(currColumn);
                if(ch == charValue1){
                    result.push_back(this->getLabel(currRow, currColumn, rowLength));
                }
        }
        currRow = row + 1;
        currColumn = column - 1;
        if(currRow < gridLength){
            if(currColumn >= 0){
                int ch = grid.at(currRow).at(currColumn);
                if(ch == charValue1){
                    result.push_back(this->getLabel(currRow, currColumn, rowLength));
                }
            }
            currColumn = column;
            int ch = grid.at(currRow).at(currColumn);
            if(ch == charValue1){
                result.push_back(this->getLabel(currRow, currColumn, rowLength));
            }
            currColumn = column + 1;
            if(currColumn < rowLength){
                int ch = grid.at(currRow).at(currColumn);
                if(ch == charValue1){
                    result.push_back(this->getLabel(currRow, currColumn, rowLength));
                }
            }
        }
        return result;
    }
};
