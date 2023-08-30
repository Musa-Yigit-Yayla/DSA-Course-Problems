#include <vector>

using namespace std;
class PathCounter{
private:
    int pathCount = 0;
    int source;
    int destination;
public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        this->pathCount = 0;
        this->source = source;
        this->destination = destination;

        bool visit[V];
        for(int i = 0; i < V; i++){
            visit[i] = false;
        }
        this->pathCounter(adj, V, visit, this->source);
        //visit[this->source] = true;
        return this->pathCount;
    }
private:
    //v represents vertex count
    //the function doesn't necessarily assume that given currVertex parameter is already marked as visited
    void pathCounter(vector<int> adj[], int v, bool visit[], int currVertex){
        if(currVertex == this->destination){
            this->pathCount++;
        }
        else{
            //retrieve the current unvisited adjacent vertices to currVertex and recursively traverse
            vector<int> unvisitedAdj;
            for(int i: adj[currVertex]){
                if(!visit[i]){
                    unvisitedAdj.push_back(i);
                }
            }
            for(int i = 0; i < unvisitedAdj.size(); i++){
                int currAdj = unvisitedAdj.at(i);
                if(!visit[currAdj]){
                    //mark the currAdj to be visited then apply recursion to it
                    visit[currAdj] = true;
                    this->pathCounter(adj, v, visit, currAdj);
                }
            }

        }
        //mark the currVertex node to be unvisited before we return
        visit[currVertex] = false;
    }
};
