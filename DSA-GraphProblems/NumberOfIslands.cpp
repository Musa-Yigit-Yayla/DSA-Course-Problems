#include <vector>

using namespace std;
class NumberOfIslands{
   private:
    vector<vector<int>> adjList;
    int rowLength;
    int gridLength;
    vector<vector<char>> grid;
  public:

    const int charValue0 = 48; //in decimal
    const int charValue1 = 49; //in decimal
    // Function to find the number of islands.
    //Passed grid must not be empty and not ragged
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        //initialize the adjList so that we have it full of empty vectors with number of grid elements
        int gridElementCount = grid.size() * grid.at(0).size();
        for(int i = 0; i < gridElementCount + 1; i++){
            vector<int> vec;
            this->adjList.push_back(vec);
        }
        this->grid = grid;
        //create a graph which is undirected and unweighted using adj list
        //we must also count the number of vertices and give them values according to their grid pos
        this->rowLength = grid.at(0).size();
        this->gridLength = grid.size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < rowLength; j++){
                int currLabel = this->getLabel(i, j, rowLength);
                //retrieve the adjacent nodes with their label
                vector<int> adjNodes = this->getAdjNodes(i, j, rowLength, gridLength, grid);
                this->adjList.at(currLabel) = adjNodes;
            }
        }

        int result = 0;
        //subsequently we must count the number of connected graphs and return it as the result
        //to do this we need to traverse each and every graph node, once we cannot go to anywhere
        //we must traverse other nodes which are not connected to the graph that we have just traversed
        bool visit[gridElementCount];
        for(int i = 0; i < gridElementCount; i++){
            visit[i] = false;
        }
        int falseIndex = this->getFalseIndex(visit, gridElementCount);
        while(falseIndex != -1){
            int currLabel = falseIndex + 1; //1 based indexing for the vertices
            this->dfs(currLabel, visit, gridElementCount);
            //increment the result which represents number of connected graphs by one
            result++;
            falseIndex = this->getFalseIndex(visit, gridElementCount);
        }
        return result;
        //notice that we regard diagonally adjacent nodes connected as well
    }
    //Iterative dfs approach
    //notice that visit is 0 based indexing whereas currLabel is 1 based indexing
    void dfs(int currLabel, bool visit[], int gridElementCount){
        stack<int> s;
        //mark currLabel as visited
        visit[currLabel - 1] = true;
        s.push(currLabel);

        while(!s.empty()){
            bool noUnvisitedAdj = true;
            int currLabel = s.top();
            int verticeRow = this->getVerticeRow(currLabel);
            int verticeColumn = this->getVerticeColumn(currLabel);//!!!MIGHT BE PROBLEMATIC PAY ATTENTION
            vector<int> currAdjacents = this->getAdjNodes(verticeRow, verticeColumn, rowLength, gridLength, grid);

            for(int i = 0; i < currAdjacents.size(); i++){
                int currAdj = currAdjacents.at(i);
                if(visit[currAdj]){
                    noUnvisitedAdj = false;
                    break;
                }
            }

            if(noUnvisitedAdj){
                //backtrack
                s.pop();
            }
            else{
                //select an unvisited vertex at currAdj push it onto the stack and mark it as visited
                int nextVertex = currAdjacents.at(0);
                s.push(nextVertex);
                visit[nextVertex] = true;
            }

        }

    }
    int getLabel(int row, int column, const int rowLength){
        return row * rowLength + column + 1; //we start counting from 1
    }
    int getVerticeRow(int label){
        int verticeRow = label / rowLength;
        return verticeRow;
    }
    int getVerticeColumn(int label){
        int verticeColumn = label % rowLength - 1;
        return verticeColumn;
    }
    //Returns the adjacent nodes if any
    vector<int> getAdjNodes(int row, int column, const int rowLength, const int gridLength, vector<vector<char>>& grid){
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
    //returns the index of the first occurence of visit, notice that this is 0 based indexing
    //returns -1 if each element evaluates to true
    int getFalseIndex(bool visit[], int length){
        int result = -1;
        for(int i = 0; i < length; i++){
            if(!visit[i]){
                result = i;
                break;
            }
        }
        return result;
    }
};
