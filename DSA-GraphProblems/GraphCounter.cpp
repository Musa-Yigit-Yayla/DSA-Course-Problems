#include <iostream>
#include <vector>
#include <cstddef>

/**
*We consider a grid to be of 0 and X characters only
*We count the number of graphs formed by X characters where adjacency is measured in 2D without diagonal direction
*/
using namespace std;
class GraphCounter{
private:
    int graphCount = 0;
    int vertexCount = 0;
    int rowCount = 0;
    int columnCount = 0;
    vector<int>* adjList = nullptr;

public:
    //Function to find the number of 'X' total shapes.
    //Assumes given grid is not empty
    int xShape(vector<vector<char>>& grid){
        if(this->adjList != NULL){
            delete[] adjList;
        }


        this->graphCount = 0;
        this->vertexCount = grid.size() * grid.at(0).size();
        this->rowCount = grid.size();
        this->columnCount = grid.at(0).size();

        bool visit[grid.size() * grid.at(0).size()];
        for(int i = 0; i < this->vertexCount; i++){
            visit[i] = false;
        }
        this->initializeAdjList(grid);
    }
    //we don't check whether adjacent labels are walls or they are visited
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
private:
    //labels are 0 based indexing
    int dfs(vector<vector<char>>& grid, bool visit[], int currLabel){

    }
    //We consider north south east and west as adjacency directions
    void initializeAdjList(vector<vector<char>>& grid){
        int v = grid.size() * grid.at(0).size();
        this->adjList = new vector<int>[v];

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.at(i).size(); j++){
                int currLabel = i * grid.at(0).size() + j;
                int labelRow = this->getLabelRow(currLabel);
                int labelColumn = this->getLabelColumn(currLabel);
                vector<int> currAdj;
                if(grid.at(labelRow).at(labelColumn) != '0'){
                    currAdj = this->getAdjLabels(currLabel);
                    for(int k = 0; k < currAdj.size(); k++){
                        int adjLabel = currAdj.at(k);
                        int adjRow = this->getLabelRow(adjLabel);
                        int adjColumn = this->getLabelColumn(adjRow);
                        if(grid.at(adjRow).at(adjColumn) == '0'){
                            //remove the blank grid nodes from the adjacency list
                            currAdj.erase(currAdj.begin() + k);
                            k--;
                        }
                    }
                }
                this->adjList.push_back(currAdj);
            }
        }

    }
};
