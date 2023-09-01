#include <vector>

using namespace std;
class MinSpanTree{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	//Notice that input grid is a 3d grid
    int spanningTree(int v, vector<vector<int>> adj[]){
        int rowLength = v / adj.size(); //row length of the grid, (e)

        //we will use prim's algorithm approach
        bool visit[v];
        for(int i = 0; i < v; i++){
            visit[i] = false;
        }
        vector<int> tree;
        int sum = 0;
        //we can select any vertex but selecting the beginning vertex would also do
        int start = adj[0].at(0); //start vertex

        while(!this->isTraversed(visit, v)){
            //retrieve the least cost edge from the tree which contains currently visited nodes
            int n1;
            int n2;
            for(int i = 0; i < )
        }
    }
    bool isTraversed(bool visit[], int n){
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                return false;
            }
        }
        return true;
    }
};
