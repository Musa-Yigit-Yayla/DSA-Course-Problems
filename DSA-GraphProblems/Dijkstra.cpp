#include <vector>
#include <cstddef>
#include <set>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;
class Dijkstra{
private:
    int** adjMatrix = nullptr;
    int matrixLength = 0;


public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s){

        this->initializeAdjMatrix(v, adj, s);
        vector<int> shortestPaths;
        set<int> vertexSet;
        vertexSet.insert(s);

        int weightArr[v];
        for(int i = 0; i < v; i++){
            int curr = this->adjMatrix[s][i];
            weightArr[i] = this->adjMatrix[s][i];
        }
        weightArr[s] = 0;

        //Second step of the dijkstra's algorithm
        for(int k = 0; k < v - 1; k++){
            //gin the smallest weighted label which is not in vertexSet
            int minWeight = INT_MAX;
            int minLabel = -1;
            for(int i = 0; i < v; i++){
                if(vertexSet.count(i) == 0 && weightArr[i] < minWeight){
                    minWeight = weightArr[i];
                    minLabel = i;
                }
            }
            //add the min label to the vertexSet
            vertexSet.insert(minLabel);


            //check weight and update it if the weight of the recently marked vertex + source to this
            //destination is smaller than the original weight
            for(int i = 0; i < v; i++){
                    int x = weightArr[i];
                    int y = weightArr[minLabel] + this->adjMatrix[minLabel][i]; //for debugging purposes
                if(vertexSet.count(i) == 0){
                     if(weightArr[i] > weightArr[minLabel] + this->adjMatrix[minLabel][i]){
                        weightArr[i] = weightArr[minLabel] + this->adjMatrix[minLabel][i];
                    }
                }
            }


        }
        //convert weight array to vector
            vector<int> result;
            for(int i = 0; i < v; i++){
                result.push_back(weightArr[i]);
            }
            return result;

    }
    void initializeAdjMatrix(int v, vector<vector<int>> adj[], int source) {
        if (this->adjMatrix != nullptr) {
            for (int i = 0; i < this->matrixLength; i++) {
                delete[] this->adjMatrix[i];
            }
            delete[] this->adjMatrix;
            this->adjMatrix = nullptr;
        }

        this->matrixLength = v;
        this->adjMatrix = new int*[v];
        for (int i = 0; i < v; i++) {
            this->adjMatrix[i] = new int[v];
            for (int j = 0; j < v; j++) {
                this->adjMatrix[i][j] = (i == j) ? 0 : INT_MAX;
            }
        }

        for (int i = 0; i < v - 1; i++) {
            vector<vector<int>> currAdjacents = adj[i]; // first column is label, second is weight
            for (vector<int> vec : currAdjacents) {
                if (vec.size() >= 2) { // Ensure that vec has at least 2 elements
                    int adjLabel = vec.at(1);
                    int adjWeight = vec.at(2);
                    this->adjMatrix[i][adjLabel] = adjWeight;
                }
            }
        }
    }


};
