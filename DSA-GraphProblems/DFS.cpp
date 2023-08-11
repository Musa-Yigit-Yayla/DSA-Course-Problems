#include <vector>
#include <stack>

using namespace std;

class DFS{

 public:
    // Function to return a list containing the DFS traversal of the graph.
    //Recursive implementation
    vector<int> dfsOfGraph(int vertexCount, vector<int> adj[]) {
        // Code here
        vector<int> result;
        int startVertex = 0;
        bool visited[vertexCount];
        for(int i = 0; i < vertexCount; i++){
            visited[i] = false;
        }
        dfsHelper(startVertex, adj, visited, result);
        return result;
    }
    void dfsHelper(int currVertex, vector<int> adj[], bool visited[], vector<int>& result){
        //mark currVertex as visited
        visited[currVertex] = 1;
        result.push_back(currVertex);

        vector<int> currAdj = adj[currVertex];
        for(int i = 0; i < currAdj.size(); i++){
            if(!visited[currAdj.at(i)]){
                visited[currAdj.at(i)] = true;
                //result.push_back(currAdj.at(i));
                this->dfsHelper(currAdj.at(i), adj, visited, result);
            }
        }
    }
    //Iterative approach, take root as the 0th element
    vector<int> dfs(int vertexCount, vector<int> adj[]){
        vector<int> result;
        stack<int> newStack;
        int currVertex = 0;
        newStack.push(currVertex);

        bool visited[vertexCount];
        for(int i = 0; i < vertexCount; i++){
            visited[i] = false;
        }

        //result.push_back(currVertex);
        while(!newStack.empty()){
            currVertex = newStack.top();
            newStack.pop();
            if(!visited[currVertex]){
                result.push_back(currVertex);
                visited[currVertex] = true;
            }
            vector<int> currAdjList = adj[currVertex];
                for(int i = currAdjList.size() - 1; i >= 0; i--){
                    int currAdj = currAdjList.at(i);
                    if(!visited[currAdj]){
                        newStack.push(currAdj);
                    }
                }
        }
        return result;
    }
};
