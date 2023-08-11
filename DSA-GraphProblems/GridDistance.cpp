#include <queue>
#include <vector>
#include <math>

using namespace std;
class Graph{
private:
    vector<int>* adjList;
    int nodeCount;
public:
    //Grid is expected to be not ragged matrix and non empty
    Graph(vector<vector<int>>& grid){
        //create an adjList of the grid elemenets
        this->nodeCount = grid.size() * grid.at(0).size();
        adjList = new vector<int>[this->nodeCount];

        int currIndex = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                vector<int> adj; // adjacency list for the current element

                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    adj.push_back(i * grid[i].size() + j - 1);
                }
                if (j + 1 < grid[i].size() && grid[i][j + 1] == 1) {
                    adj.push_back(i * grid[i].size() + j + 1);
                }
                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    adj.push_back((i - 1) * grid[i].size() + j);
                }
                if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
                    adj.push_back((i + 1) * grid[i].size() + j);
                }

                adjList[currIndex] = adj;
                currIndex++;
            }
        }
    }
    ~Graph(){
        delete[] adjList;
    }
     // BFS function to find minimum distance

    int getNodeCount() const{
        return this->nodeCount;
    }
    void bfs(bool visit[], vector<vector<int>>& dist, queue<int>& q) {
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            int currColumn = temp % dist.at(0).size();
            int currRow = temp / dist.at(0).size();

            for (int i = 0; i < adjList[temp].size(); i++) {
                if (!visit[adjList[temp][i]]) {
                    q.push(adjList[temp][i]);
                    visit[adjList[temp][i]] = true;
                    int newRow = adjList[temp][i] / dist.at(0).size();
                    int newColumn = adjList[temp][i] % dist.at(0).size();
                    dist[newRow][newColumn] = dist[currRow][currColumn] + 1;
                }
            }
        }
    }
};

class GridDistance{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>>& grid) {
        Graph myGraph(grid);

        queue<int> q;
        vector<vector<int>> result(grid.size(), vector<int>(grid.at(0).size(), 0));
        bool visit[myGraph.getNodeCount()];
        for (int i = 0; i < myGraph.getNodeCount(); i++) {
            visit[i] = false;
        }

        // Find cells with value 1 and start BFS from them
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.at(i).size(); j++) {
                if (grid[i][j] == 1) {
                    q.push(i * grid.at(0).size() + j); // Convert 2D index to 1D index
                    visit[i * grid.at(0).size() + j] = true;
                }
            }
        }

        myGraph.bfs(visit, result, q);
        return result;
    }
};
