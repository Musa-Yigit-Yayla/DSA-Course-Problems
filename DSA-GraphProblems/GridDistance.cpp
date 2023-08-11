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

                    // Only update the distance if it's greater than the new calculated distance
                    if (dist[newRow][newColumn] > dist[currRow][currColumn] + 1) {
                        dist[newRow][newColumn] = dist[currRow][currColumn] + 1;
                    }
                }
            }
        }
    }



};

class GridDistance{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize distances for cells with value 1 and push them into the queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[] = {-1, 0, 1, 0}; // Directions: Up, Right, Down, Left
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    if (result[newX][newY] > result[x][y] + 1) {
                        result[newX][newY] = result[x][y] + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }

        return result;
    }
};
