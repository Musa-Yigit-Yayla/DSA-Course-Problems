/*
*The problem is that we are given the position of a single knight in a totally empty chess board. We are required to find the minimum number of moves
*which is adequate to move our knight to a target position.
*/
#include <vector>
#include <set>
#include <climits>

using namespace std;

class StepByKnight {
    private:
    int adjMatrix[64][64];
    int adjArr[64];
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>& knightPos,vector<int>& targetPos,int N)
	{
	    // Code here
	    //A logical approach would be to simply create a weighted undirected graph where our
	    //knight can travel

	    //We need to use an adjacency matrix and then use the dijkstra's shortes path algorithm
	    //to retrieve the shortest path
	    //Also notice each and every adjacent squares' weight must be 1

	    //set all adj matrix elements to int max
	    for(int i = 0; i < 8; i++){
	        for(int j = 0; j < 8; j++){
	            if(i == j){
	                adjMatrix[i][j] = 0;
	            }
	            else{
	                adjMatrix[i][j] = INT_MAX;
	            }
	        }
	    }
	    //below loop is for setting directly adjacent squares to unit length
	    for(int i = 0; i < 8; i++){
	        for(int j = 0; j < 8; j++){
	            if(i == j){
	                continue;
	            }
	            else{
	                //retrieve the adj positions
	                int currLabel = (8 - i) * 8 + j - 1;
	                vector<vector<int>> adjPositions = this->getAdjPos(i, j);
	                for(int i = 0; i < adjPositions.size(); i++){
	                    vector<int> adjPos = adjPositions.at(i);
	                    int adjLabel = (8 - (adjPos.at(0))) * 8 + adjPos.at(1) - 1;
	                    this->adjMatrix[currLabel][adjLabel] = 1; //direct adjacency has been observed
	                }

	            }
	        }
	    }
	    //initialize the adjMatrix to infinity, adjMatrix represents shortest distance from the target pos to all other
	    //squares
	    //top left square is labeled as 0, we increase the label by 1
	    int knightLabel = (8 - (knightPos.at(0))) * 8 + knightPos.at(1) - 1;
	    int targetLabel = (8 - (targetPos.at(0))) * 8 + targetPos.at(1) - 1;
	    //set the knightLabel element to 0 since it's the starting position
	    this->adjArr[knightLabel] = 0;

	    int knightRow = knightLabel / 8;
	    int knihgtColumn = knightLabel % 8;
	    int targetRow = targetLabel / 8;
	    int targetColumn = targetLabel % 8;

	    set<int> vertexSet;
	    vertexSet.insert(knightLabel);
	    int n = 64; //number of vertices
	    for(int i = 0; i < n; i++){
	        this->adjArr[i] = this->adjMatrix[knightLabel][i];
	    }

	    //Second step to find the shortest path based on Dijkstra's algorithm
	    for(int i = 0; i < n - 1; i++){
	        //we don't necessarily need to look for the smallest weight since the curr graph has unit length weights
	        vector<int> exclusion = this->getSetExclusion(vertexSet, n);
	        if(!exclusion.empty()){
	            vector<int>::iterator it = exclusion.begin();
	            vertexSet.insert(*it);
	            for(vector<int>::iterator u = exclusion.begin(); u != exclusion.end(); u++){
	                if(this->adjArr[*u] > this->adjArr[*it] + this->adjMatrix[*it][*u]){
	                    this->adjArr[*u] = this->adjArr[*it] + this->adjMatrix[*it][*u];
	                }
	            }
	        }
	    }
	    //finally return the result
	    return this->adjArr[targetLabel];
	}
	//returns each and every vertex outside of the vertex set
	//0 based indexing
	vector<int> getSetExclusion(set<int> vertexSet, int vertexCount){
	    vector<int> result;
	    for(int i = 0; i < vertexCount; i++){
	        int currVertex = i;
	        if(vertexSet.find(currVertex) == vertexSet.end()){
	            result.push_back(currVertex);
	        }
	    }
	    return result;
	}
	//0 based indexing
	//first elt in the inner vector contains the row and the second contains the column
	vector<vector<int>> getAdjPos(int row, int column){
	    vector<vector<int>> result;
	    if(row + 2 < 8 && column + 1 < 8){
	        vector<int> moveables;
            moveables.push_back(row + 2);
            moveables.push_back(column + 1);
            result.push_back(moveables);
        }
        //1 right 2 up
        if(row + 1 < 8 && column + 2 < 8){
            vector<int> moveables;
            moveables.push_back(row + 1);
            moveables.push_back(column + 2);
            result.push_back(moveables);
        }
        //1 left 2 up
        if(row - 1 >= 0 && column + 2 < 8){
            vector<int> moveables;
            moveables.push_back(row - 1);
            moveables.push_back(column + 2);
            result.push_back(moveables);
        }
        //2 left 1 up
        if(row - 2 >= 0 && column + 1 < 8){
            vector<int> moveables;
            moveables.push_back(row - 2);
            moveables.push_back(column + 1);
            result.push_back(moveables);
        }//2 left 1 down
        if(row - 2 >= 0 && column - 1 >= 0){
            vector<int> moveables;
            moveables.push_back(row - 2);
            moveables.push_back(column - 1);
            result.push_back(moveables);
        }
        //1 left 2 down
        if(row - 1 >= 0 && column - 2 >= 0 ){
            vector<int> moveables;
            moveables.push_back(row - 1);
            moveables.push_back(column - 2);
            result.push_back(moveables);
        }
        //1 right 2 down
        if(row + 1 < 8 && column - 2 >= 0 ){
            vector<int> moveables;
            moveables.push_back(row + 1);
            moveables.push_back(column - 2);
            result.push_back(moveables);
        }
        //2 right 1 down
        if(row + 2  < 8 && column - 1 >= 0 ){
            vector<int> moveables;
            moveables.push_back(row + 2);
            moveables.push_back(column - 1);
            result.push_back(moveables);
        }
        return result;
	}
};
