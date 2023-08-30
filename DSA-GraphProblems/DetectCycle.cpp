#include <vector>
#include <cstddef>

using namespace std;
class DetectCycle{
private:
    vector<int>* adjList = nullptr;
    //we are not responsible of any deallocation since this is given by the client
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        this->adjList = adj;
        return this->dfs(V);
    }
    bool dfs(const int v){
        int rootLabel = 0;

        bool visit[v];
        for(int i = 0; i < v; i++){
            visit[i] = false;
        }
        if(this->dfsHelper(visit, v, rootLabel, -1)){
            return true;
        }
        else{
            return false;
        }
    }
    //recursive approach
    bool dfsHelper(bool visit[], const int v, int currLabel, int prevLabel){
        visit[currLabel] = true;
        vector<int> currAdj = this->adjList[currLabel];
        if(prevLabel == -1){
            //first invocation of the helper function
            //mark the currLabel as visited and apply the recursive step
            for(int i = 0; i < currAdj.size(); i++){
                if(!visit[i] && this->dfsHelper(visit, v, i, currLabel)){
                    return true;
                }
            }
        }
        else{
            //If we can see an adjacent vertex which is not the prev label and is already visited we
            //return true
            for(int i: currAdj){
                if(i != prevLabel && visit[i]){
                    return true;
                }
            }
            for(int i: currAdj){
                //apparently we haven't observed a cycle yet, hence keep going on with dfs
                if(!visit[i] && this->dfsHelper(visit, v, i, currLabel)){
                    return true;
                }
            }
        }
        return false;
    }
};
