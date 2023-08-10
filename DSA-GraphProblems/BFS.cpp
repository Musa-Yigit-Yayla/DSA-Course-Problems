#include <vector>
#include <queue>

using namespace std;
class BFS{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> returnValue;

        vector<int> regularValues;
        //retrieve the number of vertices in the graph
        for(int i = 0; i < sizeof(adj) / sizeof(adj[0]); i++){
            vector<int> currAdj = adj[i];
            for(int j = 0; j < currAdj.size(); j++){
                int currVertex = currAdj.at(j);
                if(count(regularValues.begin(), regularValues.end(), currVertex) == 0){
                    //add it to the regularValues
                    regularValues.push_back(currVertex);
                }
            }
        }
        int vertexCount = regularValues.size();
        bool visited[vertexCount + 1];
        queue<int> myQueue;
    }
};

