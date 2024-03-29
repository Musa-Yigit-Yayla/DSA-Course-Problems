#include <vector>
#include <climits>
#include <cstddef>
#include <queue>
#include <iostream>

using namespace std;
class FindPath{
private:
    int** adjMatrix = nullptr; //in adjMatrix 1 implies adjacency
    int rowCount = 0;
    int columnCount = 0;
    int matrixSize = 0;

public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        //code here
        //we can tackle this problem in terms of using dfs or bfs
        //we can only restrict oursel ves to distinguish the walls and other cells
        //subsequently we can basically traverse the maze and if we manage to reach to destination we return true

        if(this->adjMatrix != NULL){
            //deallocate the adjMatrix accordingly
            //int matrixSize = this->rowCount * this->columnCount;
            for(int i = 0; i < this->matrixSize; i++){
                delete[] adjMatrix[i];
            }
            delete[] adjMatrix;
        }
        this->rowCount = grid.size();
        this->columnCount = grid.at(0).size();
        this->matrixSize = this->rowCount * this->columnCount;
        const int matrixLength = this->matrixSize;
        this->initializeAdjMatrix(grid, matrixLength);
        //notice that we label the nodes from index 0, first vertex is labeled as 0

        //retrieve tar and dest labels respectively with a single function call
        vector<int> positions = this->retrieveTarDestLabels(grid);
        bool pathFound = false;
        if(positions.size() != 0){
            bool visit[this->matrixSize];
            //initialize the visit array to false
            for(int i = 0; i <  this->matrixSize; i++){
                visit[i] = false;
            }
            int startLabel = positions.at(0);
            int destLabel = positions.at(1);
            this->printAdjMatrix();
            this->bfs(grid, startLabel, visit);
            pathFound = visit[destLabel];
        }
        return pathFound;
    }
    int getLabel(int row, int column){
        return row * this->columnCount + column;
    }
    int getLabelRow(int label){
        return label / this->columnCount;
    }
    int getLabelColumn(int label){
        return label % this->columnCount;
    }
private:
    //after we execute our bfs starting from the startlabel we will mark every reachable vertex
    void bfs(vector<vector<int>>& grid, int startLabel, bool visit[]) {
        int vertexCount = this->matrixSize;
        int startRow = this->getLabelRow(startLabel);
        int startColumn = this->getLabelColumn(startLabel);

        queue<int> q;
        q.push(startLabel);
        visit[startLabel] = true;

        while (!q.empty()) {
            int currentLabel = q.front();
            q.pop();  // Dequeue the front node before processing neighbors

            // Get unvisited adjacent labels
            vector<int> currAdjList = this->getAdjLabels(grid, currentLabel);
            vector<int> unvisitedAdj;

            for (int adjLabel : currAdjList) {
                bool x = visit[adjLabel];
                int adjLabelRow = this->getLabelRow(adjLabel);
                int adjLabelColumn = this->getLabelColumn(adjLabel);
                if (!visit[adjLabel] && grid.at(adjLabelRow).at(adjLabelColumn) != 0) {
                    unvisitedAdj.push_back(adjLabel);
                }
            }

            if (!unvisitedAdj.empty()) {
                // Enqueue unvisited adjacent nodes and mark them as visited
                for (int adjLabel : unvisitedAdj) {
                    q.push(adjLabel);
                    visit[adjLabel] = true;
                }
            }
            // No unvisited adjacent nodes, continue to backtrack
        }
    }
    //Invoke when adjMatrix has been deallocated so as to avoid memory leak
    void initializeAdjMatrix(vector<vector<int>>& grid, const int matrixLength){
        //notice we cannot move diagonally and we only consider direct adjacency


        this->adjMatrix = new int*[matrixLength];


        //initialize each and every matrix element to infinity initially
        for(int i = 0; i < this->matrixSize; i++){
            this->adjMatrix[i] = new int[matrixLength];
            for(int j = 0; j < this->matrixSize; j++){
                this->adjMatrix[i][j] = INT_MAX;
            }
        }
        for(int i = 0; i < this->matrixSize; i++){
            //i represents the current label
            //if a label pos contains a wall (0), then we must neglect it on adjacency
            int currLabel = i;
            int labelRow = this->getLabelRow(currLabel);
            int labelColumn = this->getLabelColumn(currLabel);
            if(grid.at(labelRow).at(labelColumn) != 0){
                vector<int> adjVertices = this->getAdjLabels(grid, currLabel);
                for(int adjLabel: adjVertices){
                    int adjRow = this->getLabelRow(adjLabel);
                    int adjColumn = this->getLabelColumn(adjColumn);

                    if(grid.at(adjRow).at(adjColumn) != 0){
                        this->adjMatrix[currLabel][adjLabel] = 1;
                    }
                }
            }
        }
    }
    //we don't check whether adjacent labels are walls or they are visited
    vector<int> getAdjLabels(vector<vector<int>>& grid, int label){
        int labelRow = this->getLabelRow(label);
        int labelColumn = this->getLabelColumn(label);

        vector<int> result;

        //check top vertex
        int currRow = labelRow - 1;
        int currColumn = labelColumn;

        int nextLabel;

        if(currRow >= 0){
            nextLabel = this->getLabel(currRow, currColumn);
            result.push_back(nextLabel);
        }
        //check left
        currRow =  labelRow;
        currColumn = labelColumn - 1;
        if(currColumn  >= 0){
            nextLabel = this->getLabel(currRow, currColumn);
            result.push_back(nextLabel);
        }
        //check bottom
        currRow =  labelRow + 1;
        currColumn = labelColumn;
        if(currRow < this->rowCount){
            nextLabel = this->getLabel(currRow, currColumn);
            result.push_back(nextLabel);
        }
        //check right
        currRow =  labelRow;
        currColumn = labelColumn + 1;
        if(currColumn < this->columnCount){
            nextLabel = this->getLabel(currRow, currColumn);
            result.push_back(nextLabel);
        }
        return result;
    }
    //Return empty vector if one or more of the elements do not exist
    vector<int> retrieveTarDestLabels(vector<vector<int>>& grid){
        //1 means tar, 2 means dest
        vector<int> result;
        int tar = -1;
        int dest = -1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.at(i).size(); j++){
                int curr = grid.at(i).at(j);
                if(curr == 1){
                    tar = this->getLabel(i, j);
                }
                else if(curr == 2){
                    dest = this->getLabel(i, j);
                }
                if(tar != -1 && dest != -1){
                    result.push_back(tar);
                    result.push_back(dest);
                    return result;
                }
            }
        }
        return result;
    }
    void printAdjMatrix(){
        for(int i = 0; i < this->matrixSize; i++){
            for(int j = 0; j < this->matrixSize; j++){
                cout << this->adjMatrix[i][j] << ", ";
            }
            cout << endl;
        }
    }
};
