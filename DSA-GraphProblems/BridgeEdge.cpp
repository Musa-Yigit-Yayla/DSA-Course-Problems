#include <vector>
#include <queue>
#include <iostream>

using namespace std;
class BridgeEdge{
public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int v, vector<int> adj[], int c, int d){
        //we can apply a bfs approach that avoids going through the given path
        //If we can visit each and every node without using the given path then we return 0 else 1
        bool visit[v];
        for(int i = 0; i < v; i++){
            visit[i] = false;
        }
        this->bfs(adj, v, visit, c, d);
        return !isTraversed(visit, v);
    }
    //This is a specialized version of bfs function which avoids using the path between vertices c and d
    void bfs(vector<int> adj[], int v, bool visit[], int c, int d){
        queue<int> q;
        //mark the source label as visited and let the source label be 0
        int source = 0;
        q.push(source);
        visit[source] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            //retrieve the adjacency list of front element
            vector<int> currAdjList = adj[front];
            vector<int> unvisitedAdj;
            for(int i: currAdjList){
                if(!visit[i]){
                    unvisitedAdj.push_back(i);
                }
            }
            for(int adjLabel: unvisitedAdj){
                if(!((front == c && adjLabel == d) || (front == d && adjLabel == c))){
                    //we can use this path
                    q.push(adjLabel);
                    visit[adjLabel] = true;
                }
            }

        }
    }
    static bool isTraversed(bool visit[], int n){
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                return false;
            }
        }
        return true;
    }
};
