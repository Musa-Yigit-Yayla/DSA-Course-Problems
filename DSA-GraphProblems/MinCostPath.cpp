#include <vector>
#include <queue>
#include <climits>

using namespace std;
class MinCostPath{
private:
    int rowCount;
    int columnCount;
public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here
        this->rowCount = grid.size();
        this->columnCount = grid.at(0).size();
        int startLabel = 0;
        int vertexCount;
        int tarLabel = grid.size() * grid.at(0).size() - 1;
        vertexCount = tarLabel + 1;
        vector<int> costGrid;
        vector<bool> visit(vertexCount, false);
        //we need to utilize such a traversal that we favor visiting the least cost unvisited adjacent first
        //we can use dijktra's algorithm
        priority_queue<int> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.at(i).size(); j++){
                costGrid.push_back(INT_MAX);
            }
        }
        costGrid.at(0) = grid.at(0).at(0);
        q.push(startLabel);
        visit.at(startLabel) = true;

        while(!q.empty()){
            int currCell = q.top();
            int currRow = this->getLabelRow(currCell);
            int currColumn = this->getLabelColumn(currCell);
            q.pop();

            if(currCell == tarLabel){
                return costGrid.at(tarLabel);
            }
            vector<int> currAdj = this->getAdjLabels(currCell);
            vector<int> unvisitedAdj;
            for(int i: currAdj){
                if(!visit.at(i)){
                    unvisitedAdj.push_back(i);
                }
            }
            for(int i: unvisitedAdj){
                int rowI = this->getLabelRow(i);
                int columnI = this->getLabelColumn(i);
                int newCost = costGrid.at(currCell) + grid.at(rowI).at(columnI) + grid.at(currRow).at(currColumn);
                if(newCost < costGrid.at(i) && !visit.at(i)){
                    costGrid.at(i) = newCost;
                    q.push(i);
                    visit.at(i) = true;
                }
            }
        }
        return -1;
    }
    vector<int> getAdjLabels( int label){
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
    int getLabel(int row, int column){
        return row * this->columnCount + column;
    }
    int getLabelRow(int label){
        return label / this->columnCount;
    }
    int getLabelColumn(int label){
        return label % this->columnCount;
    }
};
