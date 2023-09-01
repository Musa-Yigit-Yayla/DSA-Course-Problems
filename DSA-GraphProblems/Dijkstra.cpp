#include <vector>
#include <cstddef>
#include <unordered_set>

using namespace std;
class Dijkstra{
private:
    int** adjMatrix = nullptr;
    int matrixLength = 0;


public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s){

        this->initializeAdjMatrix(vector<vector<int>> adj[], int source);
        vector<int> shortestPaths;
        set<int> vertexSet;

    }
    void initializeAdjMatrix(int v, vector<vector<int>> adj[], int source){
        if(this->adjMatrix != NULL){
            for(int i = this->matrixLength; i < this->matrixLength; i++){
                int* currArr = this->adjMatrix[i];
                delete[] currArr;
            }
            delete[] this->adjMatrix;
            this->adjMatrix = nullptr;
        }
        this->adjMatrix = new int[v][v];
        this->matrixLength = v;

        for(int i = 0; i < v; i++){
            //set the entire row to int max initially
            for(int j = 0; j < v; j++){
                this->matrix[i][j] = INT_MAX;
            }
            vector<vector<int>> currAdjacents = adj[i]; //first column is label, second is weight
            for(vector<int> vec: currAdjacents){
                int adjLabel = vec.at(0);
                int adjWeight = vec.at(1);

                this->matrix[i][adjLabel] = adjWeight;
            }
        }
    }

};
