#include <vector>
#include <cstddef>

using namespace std;
class DetectCycle{
private:
    vector<int>* adjList = nullptr;
    //we are not responsible of any deallocation since this is given by the client
public:
    bool isCycle(int v, vector<int> adj[]) {
        this->adjList = adj;
        bool visit[v];
        for (int i = 0; i < v; i++) {
            visit[i] = false;
        }
        for (int i = 0; i < v; i++) {
            if (!visit[i] && this->dfs(i, visit, v)) {
                return true;
            }
        }
        return false;
    }

    bool dfs(int rootLabel, bool visit[], const int v) {
        if (this->dfsHelper(visit, v, rootLabel, -1)) {
            return true;
        } else {
            return false;
        }
    }

    bool dfsHelper(bool visit[], const int v, int currLabel, int prevLabel) {
        visit[currLabel] = true;
        vector<int> currAdj = this->adjList[currLabel];

        if (prevLabel == -1) {
            for (int i = 0; i < currAdj.size(); i++) {
                if (!visit[currAdj[i]] && this->dfsHelper(visit, v, currAdj[i], currLabel)) {
                    return true;
                }
            }
        } else {
            for (int i : currAdj) {
                if (i != prevLabel && visit[i]) {
                    return true;
                }
            }
            for (int i : currAdj) {
                if (!visit[i] && this->dfsHelper(visit, v, i, currLabel)) {
                    return true;
                }
            }
        }
        return false;
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
