#include <vector>
#include <climits>
#include <cstddef>

using namespace std;
class FindPath{
private:
    int** adjMatrix = nullptr;
    int rowCount;
    int columnCount;
    int matrixSize;

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
        this->initializeAdjMatrix(grid);
        //notice that we label the nodes from index 0, first vertex is labeled as 0

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
    void bfs(vector<vector<int>>& visit, int startLabel){

    }
    //Invoke when adjMatrix has been deallocated so as to avoid memory leak
    void initializeAdjMatrix(vector<vector<int>>& grid){
        //notice we cannot move diagonally and we only consider direct adjacency
        this->rowCount = grid.size();
        this->columnCount = grid.at(0).size;
        this->matrixSize = this->rowCount * this->columnCount;

        this->adjMatrix = new int[this->matrixSize][this->matrixSize];

        //initialize each and every matrix element to infinity initially
        for(int i = 0; i < this->matrixSize; i++){
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
                this->getAdjLabels(grid, label);
            }
        }
    }
    vector<int> getAdjLabels(vector<vector<int>>& grid, int label){
        int labelRow = this->getLabelRow(label);
        int labelColumn = this->getLabelColumn(label);

        vector<int> result;

        //check top vertex
        int currRow = labelRow - 1;
        int currColumn = labelColumn;

        int nextLabel;

        if(currRow >= 0){
            nextLabel = this->getLabel(currRow, curreColumn);
            result.push_back(nextLabel);
        }
        //check left
        currRow =  labelRow;
        currColumn = labelColumn - 1;
        if(currColumn  >= 0){
            nextLabel = this->getLabel(currRow, curreColumn);
            result.push_back(nextLabel);
        }
        //check bottom
        currRow =  labelRow + 1;
        currColumn = labelColumn;
        if(currRow < this->rowCount){
            nextLabel = this->getLabel(currRow, curreColumn);
            result.push_back(nextLabel);
        }
        //check right
        currRow =  labelRow;
        currColumn = labelColumn + 1;
        if(currColumn < this->columnCount){
            nextLabel = this->getLabel(currRow, curreColumn);
            result.push_back(nextLabel);
        }
        return result;
    }

};
