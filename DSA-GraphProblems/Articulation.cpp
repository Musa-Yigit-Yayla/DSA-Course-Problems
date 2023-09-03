#include <stack>
#include <vector>

using namespace std;
class Articulation{
public:
  //We expect user to provide us a graph such that the vertices are labeled consecutively starting from 0
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        // Code here
        //One approach is that we can disregard each and every vertex once in a loop and check whether
        //once we disregard a specific vertex if we can travel to all other vertices in a single traversal
        vector<int> result;
        if(v <= 2){ //&& adj[0].size() > 0){
            //result.push_back(0);
            //result.push_back(1);
            result.push_back(-1);
            return result;
        }


        for(int i = 0; i < v; i++){
            bool visit[v];
            int removedVertex = i;
            for(int j = 0; j < v; j++){
                visit[j] = false;
            }
            visit[removedVertex] = true;
            this->dfsHelper(adj, visit, v, removedVertex);
            if(!isTraversed(visit, v)){
                result.push_back(removedVertex);
            }
        }
        if(result.size() == 0){
            result.push_back(-1);
        }
        return result;
    }
    //This method tries to dfs a graph where we do not pass from a vertex
    void dfsHelper(vector<int> adj[], bool visit[], int v, int removedVertex){
        stack<int> s;
        int source;
        if(removedVertex == 0){
            source = 1;
        }
        else{
            source = 0;
        }
        s.push(source);
        visit[source] = true;

        while(!s.empty()){
            int top = s.top();
            s.pop();

            //get unvisited adjacents of the current label
            vector<int> currAdj = adj[top];
            for(int adjLabel: currAdj){
                if(!visit[adjLabel]){
                    s.push(adjLabel);
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
