#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
class BFS{
public:
    // Function to return Breadth First Traversal of given graph.
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
        //returnValue.push_back(startVertex);
        //visited[startVertex] = true;
        while(!q.empty()){
            int curr = q.front();

            //visited[curr] = true;
            q.pop();
            //if(!visited[curr]){
            if(count(returnValue.begin(), returnValue.end(), curr) == 0){
                returnValue.push_back(curr);
            }
            //}
            for(int i = 0; i < adj[curr].size(); i++){
                int currAdj = adj[curr].at(i);
                if(!visited[currAdj]){
                    q.push(currAdj);
                    visited[currAdj] = true;
                }
            }
        }
        return returnValue;
    }
};

