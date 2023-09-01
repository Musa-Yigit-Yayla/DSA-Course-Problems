#include <vector>
#include <cstddef>
#include <set>
#include <climits>
#include <algorithm>

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
            weightArr[i] = this->adjMatrix[s][i];
        }
        weightArr[s] = 0;

        //Second step of the dijkstra's algorithm
        for(int i = 0; i < v - 1; i++){
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
                if(vertexSet.count(i) == 0){
                    if(weightArr[i] < weightArr[minLabel] + this->adjMatrix[minLabel][i]){
                        weightArr[i] = weightArr[minLabel] + this->adjMatrix[minLabel][i];
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
        const int size = v;
        this->adjMatrix = new int*[size];
        for(int i = 0; i < size; i++){
            this->adjMatrix[i] = new int[size];
        }
        this->matrixLength = v;

        for(int i = 0; i < v; i++){
            //set the entire row to int max initially
            for(int j = 0; j < v; j++){
                this->adjMatrix[i][j] = INT_MAX;
            }
            vector<vector<int>> currAdjacents = adj[i]; //first column is label, second is weight
            for(vector<int> vec: currAdjacents){
                int adjLabel = vec.at(0);
                int adjWeight = vec.at(1);

                this->adjMatrix[i][adjLabel] = adjWeight;
            }
        }
    }

};
