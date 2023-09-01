#include <vector>
#include <queue>
#include <cstddef>

using namespace std;
class LargestArea{
private:
    int rowCount = 0;
    int columnCount = 0;
    vector<int>* adjList = nullptr;
    vector<int> areaCounter; //counts then umber of nodes of each graph in the given grid

public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        if(this->adjList != NULL){
            areaCounter.clear();
            delete[] adjList;
            this->adjList = nullptr;
        }


        this->rowCount = grid.size();
        this->columnCount = grid.at(0).size();
        int nodeCount = this->rowCount * this->columnCount;
        this->adjList = new vector<int>[nodeCount];
        this->initializeAdjList(grid);
        vector<bool> visit(nodeCount, false);
        //iterate through the grid so as to set the 0 valued labels' visit correspondance to true
        for(int i = 0; i < nodeCount; i++){
            int currLabel = i;
            int currRow = this->getLabelRow(currLabel);
            int currColumn = this->getLabelColumn(currLabel);

            if(grid.at(currRow).at(currColumn) == 0){
                visit.at(currLabel) = true;
            }
        }
        int startLabel = this->getFalseIndex(visit);
        while(this->getFalseIndex(visit) != -1){
            this->bfs(grid, visit, nodeCount, startLabel);
        }
        int result = 0;
        if(this->areaCounter.size() != 0){
            result = this->areaCounter.at(0);
            for(int area: areaCounter){
                if(area > result){
                    result = area;
                }
            }
        }
        return result;
    }
    //This bfs function counts the total number of visited nodes on each call and pushes them into
    //the areaCounter at each call
    //Given start label must be a valid label, not a 0 valued label which indicates a wall
    void bfs(vector<vector<int>>& grid, vector<bool>& visit, int v, int start){
        queue<int> q;
        //enqueue the start and mark it as visited
        q.push(start);
        visit[start] = true;

        int result = 1;
        while(!q.empty()){
            int front = q.front();
            q.pop();

            vector<int> adjNodes = this->adjList[front];
            for(int adj: adjNodes){
                if(!visit[adj]){
                    q.push(adj);
                    visit[adj] = true;
                    result++;
                }
            }
        }
        this->areaCounter.push_back(result);
    }
    //get the adjacent labels of the given label, diagonal adjacency is valid
    //Returns the adjacent nodes if any
    vector<int> getAdjNodes(int row, int column, const int rowLength, const int gridLength, vector<vector<int>>& grid){
        vector<int> result;
        //start from top left
        int currRow = row - 1;
        int currColumn = column - 1;
        if(currRow >= 0){
            if(currColumn >= 0){
                int ch = grid.at(currRow).at(currColumn);
                //if(ch == charValue1){
                    result.push_back(this->getLabel(currRow, currColumn, rowLength));
                //}
            }
            currColumn = column;
            int ch = grid.at(currRow).at(currColumn);
            //if(ch == charValue1){
                result.push_back(this->getLabel(currRow, currColumn, rowLength));
            //}
            currColumn = column + 1;
            if(currColumn < rowLength){
                int ch = grid.at(currRow).at(currColumn);
                //if(ch == charValue1){
                    result.push_back(this->getLabel(currRow, currColumn, rowLength));
                //}
            }
        }
        currRow = row;
        currColumn = column - 1;
        if(currColumn >= 0){
            int ch = grid.at(currRow).at(currColumn);
            //if(ch == charValue1){
                result.push_back(this->getLabel(currRow, currColumn, rowLength));
            //}
        }
        //disregard the piece's position itself since we use adjList
        currColumn = column + 1;
        if(currColumn < rowLength){
            int ch = grid.at(currRow).at(currColumn);
                //if(ch == charValue1){
                    result.push_back(this->getLabel(currRow, currColumn, rowLength));
                //}
        }
        currRow = row + 1;
        currColumn = column - 1;
        if(currRow < gridLength){
            if(currColumn >= 0){
                int ch = grid.at(currRow).at(currColumn);
                //if(ch == charValue1){
                    result.push_back(this->getLabel(currRow, currColumn, rowLength));
                //}
            }
            currColumn = column;
            int ch = grid.at(currRow).at(currColumn);
            //if(ch == charValue1){
                result.push_back(this->getLabel(currRow, currColumn, rowLength));
            //}
            currColumn = column + 1;
            if(currColumn < rowLength){
                int ch = grid.at(currRow).at(currColumn);
                //if(ch == charValue1){
                    result.push_back(this->getLabel(currRow, currColumn, rowLength));
                //}
            }
        }
        return result;
    }
    int getLabel(int row, int column){
        return row * this->columnCount + column;
    }
    int getLabel(int row, int column, const int rowLength){
        return row * rowLength + column;
    }
    int getLabelRow(int label){
        return label / this->columnCount;
    }
    int getLabelColumn(int label){
        return label % this->columnCount;
    }
    //returns the index of the first occurence of visit, notice that this is 0 based indexing
    //returns -1 if each element evaluates to true
    int getFalseIndex(vector<bool> visit){
        int result = -1;
        int length = visit.size();
        for(int i = 0; i < length; i++){
            if(!visit[i]){
                result = i;
                break;
            }
        }
        return result;
    }
private:
    //This function disregards the nodes with 0
    void initializeAdjList(vector<vector<int>>& grid){
        //adjList has been created already we just have to initialize it
        for(int i = 0; i < this->rowCount; i++){
            for(int j = 0; j < this->columnCount; j++){
                vector<int> validAdj;
                int currLabel = this->getLabel(i, j);
                if(grid.at(i).at(j) != 0){
                    vector<int> currAdj = this->getAdjNodes(i, j, this->columnCount, this->rowCount, grid);
                    for(int adjLabel: currAdj){
                        int adjRow = this->getLabelRow(adjLabel);
                        int adjColumn = this->getLabelColumn(adjLabel);
                        if(grid.at(adjRow).at(adjColumn) != 0){
                            //this is a valid adjacent node
                            validAdj.push_back(adjLabel);
                        }

                    }
                }
                this->adjList[currLabel] = validAdj;
            }
        }
    }
};
