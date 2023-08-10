#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
class BFS{
public:
    // Function to return Breadth First Traversal of given graph.
    public:
    vector<int> bfsOfGraph(int vertexCount, vector<int> adj[]) {
        vector<int> returnValue;
        int startVertex = 0;

        bool visited[vertexCount];
        for(int i = 0; i < vertexCount; i++){
            visited[i] = false;
        }
        queue<int> q;
        //push the first vertex into the queue
        q.push(startVertex);
        while(!q.empty()){
            int curr = q.front();
            visited[curr] = true;
            returnValue.push_back(curr);
            q.pop();
            for(int i = 0; i < adj[curr].size(); i++){
                int currAdj = adj[curr].at(i);
                if(!visited[currAdj]){
                    q.push(currAdj);
                    visited[currAdj];
                }
            }
        }
        return returnValue;
    }
};

